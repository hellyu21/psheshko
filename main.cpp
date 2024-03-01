#include <SFML/Graphics.hpp>
#include <figures.hpp>
#include <gra.hpp>

int main()
{
    lu::Gra gra(1000, 600, "Game");
    gra.Setup();

    gra.LifeCycle();

    return 0;
}