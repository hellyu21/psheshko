#include <SFML/Graphics.hpp>
#include <text.hpp>
#include <prog.hpp>

int main()
{
    lu::Gra gra(1000, 600);
    gra.Setup();

    gra.LifeCycle();

    return 0;
}