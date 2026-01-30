#pragma once
#include <SFML/Graphics.hpp>
#include "Tomas.h"
#include "Plataforma.h"

using namespace std;
using namespace sf;

// Classe principal del joc
class Joc
{
private: //dades
    RenderWindow window;
    Tomas jugador;
    Clock rellotge;
    Font font;
    Text instruccionsText;
    MapaPlataformes carregadorNivells;

public://metodes
    Joc();
    void run();

private: //metodes
    void controlarEntrada();
    void actualitzacio(float dt);
    void draw();
    void comprovarColisions(Personatge& Personatge);
    void comprovarObjectiu(Plataforma objectiu);


};
