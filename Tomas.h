#pragma once
#include "Personatge.h"
class Tomas : public Personatge
{
public:
    Tomas(float x, float y);

    void controlarEntrada() override;
};
