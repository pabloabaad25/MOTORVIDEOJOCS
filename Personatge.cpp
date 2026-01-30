#include "Personatge.h"

using namespace std;
using namespace sf;
Personatge::Personatge(float x, float y, float spd, float jmp)
    : GameObject(x, y, 40, 60) {
    velocitat = Vector2f(0, 0);
    estaSaltant = false;
    speed = spd;
    forsaSaltant = jmp;
}

void Personatge::actualitzacio(float dt) {}

void Personatge::actualitzacio(float dt, int MaxX, int MaxY)
{
    // Aplica gravetat
    velocitat.y += GRAVETAT * dt;

    // Actualitza posició
    posicio.x += velocitat.x * dt;
    posicio.y += velocitat.y * dt;

    // Col·lisió amb el terra (simplificat)
    if (posicio.y > MaxY - 100)
    {
        posicio.y = MaxY - 100;
        velocitat.y = 0;
        estaSaltant = false;
    }

    // Límits laterals
    if (posicio.x < 0) posicio.x = 0;
    if (posicio.x > MaxX) posicio.x = MaxX;

    forma.setPosition(posicio);
}
void Personatge::setPosition(float x, float y) {
    posicio = Vector2f(x, y);
    forma.setPosition(posicio);
}

void Personatge::stopFalling(float groundY) {
    posicio.y = groundY;
    velocitat.y = 0;
    estaSaltant = false;
    forma.setPosition(posicio);
}
