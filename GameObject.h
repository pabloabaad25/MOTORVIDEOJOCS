#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

// Classe base per a tots els objectes del joc
class GameObject
{
protected:
    // Atributs accessibles per les classes heretades (Personatge, Plataforma, etc.)
    Vector2f posicio;           // Vector de posició bidimensional (x, y)
    RectangleShape forma;       // Forma rectangular gràfica de l'objecte

public:
    // Constructor amb coordenades (x, y) i dimensions (amplada, alçada)
    GameObject(float x, float y, float amplada, float alcada);

    // Mètode virtual pur: obliga les classes filles a implementar-lo
    virtual void actualitzacio(float dt) = 0;

    // Dibuixa l'objecte a la finestra
    virtual void dibuixar(RenderWindow& finestra);

    // Obté l'àrea de col·lisió (bounding box)
    FloatRect getLimits();

    // Retorna la posició actual
    Vector2f getPosicio();

    // Estableix una nova posició al mapa
    void setPosicio(float x, float y);
};