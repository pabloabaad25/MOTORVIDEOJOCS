#include "GameObject.h"

using namespace std;
using namespace sf;

// Constructor amb posició, amplada i alçada
GameObject::GameObject(float x, float y, float amplada, float alcada)
{
    posicio = Vector2f(x, y);              // Defineix les coordenades del vector
    forma.setSize(Vector2f(amplada, alcada)); // Assigna dimensions al rectangle
    forma.setPosition(posicio);               // Ubica el rectangle al mapa
}

// Dibuixa l'objecte a la finestra
void GameObject::dibuixar(RenderWindow& finestra)
{
    finestra.draw(forma); // Renderitza la forma gràfica
}

// Retorna l'àrea de col·lisió (bounding box)
FloatRect GameObject::getLimits()
{
    return forma.getGlobalBounds(); // Obté el rectangle de límits
}

// Obté la posició actual de l'objecte
Vector2f GameObject::getPosicio()
{
    return posicio; // Retorna el vector posició
}

// Canvia la ubicació de l'objecte
void GameObject::setPosicio(float x, float y)
{
    posicio = Vector2f(x, y);    // Actualitza el vector coordenades
    forma.setPosition(posicio);     // Mou la forma gràfica
}