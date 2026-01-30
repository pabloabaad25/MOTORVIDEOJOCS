#include "Tomas.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

Tomas::Tomas(float x, float y) : Personatge(x, y, 250.0f, -450.0f)
{
    forma.setFillColor(Color::Green);
}

void Tomas::controlarEntrada()
{
    // Controls: WASD
    velocitat.x = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        velocitat.x = -speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        velocitat.x = speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !estaSaltant)
    {
        velocitat.y = forsaSaltant;
        estaSaltant = true;
    }
}
