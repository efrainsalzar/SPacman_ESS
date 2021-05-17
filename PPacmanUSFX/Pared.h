#pragma once
#include "GameObject.h"
#include "TileGraph.h"
//#include "TextureManager.h"
//#include "TextureAnimation.h"

class Pared : public GameObject
{
private:
    Tile* tileActual;
    //TextureAnimation* texturaAnimacion;

public:
    Pared(Tile* _tile, Texture* _paredTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
    Tile* getTile() { return tileActual; }
    void setTile(Tile* _tileNuevo);
    
    //void render() override;
};

