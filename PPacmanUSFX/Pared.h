#pragma once
#include "GameObject.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "TextureAnimation.h"

class Pared : public GameObject
{
protected:
    Tile* tileActual;
    TextureAnimation* texturaAnimacion;

public:
    Pared(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY);
    Tile* getTile() { return tileActual; }
    void setTile(Tile* _tileNuevo);
    
    virtual void render() {};
};

