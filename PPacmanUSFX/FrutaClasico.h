#pragma once
#include "Fruta.h"
class FrutaClasico :
    public Fruta
{
public: 
    FrutaClasico(Tile* _tile, Texture* _frutaTexture, int _posicionX, int _posicionY);
    ~FrutaClasico();

    void render() override;
    void update() override;
};

