#pragma once
#include "Pared.h"
class ParedClasico :
    public Pared
{
public:
    ParedClasico(Tile* _tile, Texture* _paredTexture, int _posicionX, int _posicionY);

    void render() override;

};

