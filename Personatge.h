#pragma once
#include "GameObject.h"
// Classe DERIVADA per a personatges jugables
class Personatge : public GameObject
{
protected:
    Vector2f velocitat;
    bool estaSaltant;

    const float GRAVETAT = 800.0f;
    float speed;
    float forsaSaltant;
private:
    void actualitzacio(float dt) override;
public:
    Personatge(float x, float y, float spd, float jmp);

    virtual void controlarEntrada() = 0;  // Cada personatge té els seus controls

    void actualitzacio(float dt, int MaxX, int MaxY);

    void setPosition(float x, float y);

    void stopFalling(float groundY);
};
