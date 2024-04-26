using namespace std;

namespace lu
{

  class Mytext
  {
    int width;
    int height;
    float showtime;
    string capture;
    string text;
    sf::Text Mess;
    sf::Font font;
    sf::RenderWindow window;

  public:
    Mytext(int gotwidth, int gotheight)
    {
      width = gotwidth;
      height = gotheight;
    }

    void Setup(string gottext, float gotshowtime)
    {
      text = gottext;
      showtime = gotshowtime;
      window.create(sf::VideoMode(width, height), "Text");
      Mess.setColor(sf::Color::White);
      Mess.setFont(font);

    }

    void verbAnimationText()
    {
      sf::Clock Clock;
      clock_t start = clock();

      int lenght = 1;
      sf::Color colorback;
      bool flag = 1;
      sf::Music music;
      music.openFromFile("applause_1.ogg");

      bool first_sleep = 1;
      while (window.isOpen())
      {

        sf::Event event;
        while (window.pollEvent(event))
        {
          if (event.type == sf::Event::Closed)
            window.close();
        }

        if (lenght < (text.size()+1) && lenght < 10)
        {
          Mess.setString(text.substr(0, lenght));

        }
        float dt = Clock.getElapsedTime().asSeconds();

        if (first_sleep)
        {
          first_sleep = 0;
        }
        else if (showtime / text.size() > dt)
        {
          std::cout << "Проверка #1" << std::endl;
          sf::Time t = sf::seconds(showtime / (text.size()-1) - dt);
          sf::sleep(t);
        }

        clock_t end = clock();
        cout << end - start << endl;
        Clock.restart();

        if (!font.loadFromFile("DuskDemon.ttf"))
        {
          std::cout << "Error while loading arial.ttf" << std::endl;
        }
        if (lenght < (text.size()+1) && lenght < 10)
        {
          cout << "Проверка #1" << endl;
          sf::Color colortext(rand() % 256, rand() % 256, rand() % 256);
          Mess.setColor(colortext);
          colorback.r = rand() % 256;
          colorback.g = rand() % 256;
          colorback.b = rand() % 256;
          window.clear(colorback);
          lenght += 1;
          if (lenght == (text.size() + 1))
          {
            cout << "hhhh";
            music.play();
            flag = 0;
          }

        }

        window.clear(colorback);

        window.draw(Mess);
        window.display();
      }
    }
  };

}  
