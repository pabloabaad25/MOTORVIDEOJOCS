#include "Joc.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

Joc::Joc() :
    window(VideoMode({ 800, 600 }), "Joc de Plataformes Simple"),
    jugador(100, 100),
    font("KOMIKAP_.ttf"),
    instruccionsText(font)
{
    window.setFramerateLimit(60);
    if (carregadorNivells.carregaDesdeFitxer("level1.txt", window))
    {
        jugador.setPosition(carregadorNivells.getPosicioInicialJugador().x, carregadorNivells.getPosicioInicialJugador().y);
    }
    //instruccionsText.setFont(font);
    instruccionsText.setString("Thomas (VERD): WASD \nArribeu tots dos a la meta groga!\nNivell carregat des de: level1.txt");
    instruccionsText.setCharacterSize(16);
    instruccionsText.setFillColor(Color::Black);
    instruccionsText.setPosition({ 10, 10 });
}

void Joc::actualitzacio(float dt)
{


    // Actualitza personatges
    jugador.actualitzacio(dt, window.getSize().x, window.getSize().y);
    carregadorNivells.actualitzacio(dt);
    comprovarColisions(jugador);
    comprovarObjectiu(carregadorNivells.getobjectiu());

}

void Joc::comprovarObjectiu(Plataforma objectiu)
{
    if (jugador.getLimits().findIntersection(objectiu.getLimits()) //&&
        //bob.getLimits().findIntersection(objectiu.getLimits())
        )
    {
        std::cout << "Felicitats! Tots dos heu arribat a la meta!" << std::endl;
        // Reinicia posicions
        if (carregadorNivells.carregaDesdeFitxer("level2.txt", window))
        {
            jugador.setPosition(carregadorNivells.getPosicioInicialJugador().x, carregadorNivells.getPosicioInicialJugador().y);
        }
    }
}

void Joc::controlarEntrada() {
    // GESTIÓ D’ESDEVENIMENTS
    while (const std::optional event = window.pollEvent()) {
        if (event->is<Event::Closed>()) window.close();
        if (const auto* key = event->getIf<Event::KeyPressed>()) {
            if (key->scancode == Keyboard::Scancode::Escape) {
                window.close();
            }
        }
        // Cada personatge gestiona el seu input (polimorfisme!)
        jugador.controlarEntrada();
    }
}

void Joc::run() {
    while (window.isOpen()) {
        float dt = rellotge.restart().asSeconds();

        controlarEntrada();
        actualitzacio(dt);
        draw();
    }
}


void Joc::draw()
{
    window.clear(Color::White);

    // Dibuixa plataformes (polimorfisme amb JocObject!)
    carregadorNivells.dibuixar(window);
    // Dibuixa personatges
    jugador.dibuixar(window);

    // Dibuixa instruccions
    window.draw(instruccionsText);

    window.display();
}

void Joc::comprovarColisions(Personatge& Personatge)
{
    FloatRect limits_caracters = Personatge.getLimits();
    vector <Plataforma> ConjuntPlataforma;
    ConjuntPlataforma = carregadorNivells.getPlataforma();

    for (auto& Plataforma : ConjuntPlataforma)
    {
        FloatRect limits_plataforma = Plataforma.getLimits();

        if (const std::optional intersection = (limits_caracters.findIntersection(limits_plataforma)))
        {
            // Col·lisió des de dalt
            if (limits_caracters.position.y < limits_plataforma.position.y &&
                limits_caracters.position.y + limits_caracters.size.y < limits_plataforma.position.y + 15)
            {
                Personatge.stopFalling(limits_plataforma.position.y - limits_caracters.size.y);
            }
        }
    }
}




