#pragma once
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "TextureAnimation.h"

//enum PODER_MONEDA {
//    PODER_MONEDA_NINGUNO,
//    PODER_MONEDA_CRECIMIENTO,
//    PODER_MONEDA_COMER,
//    PODER_MONEDA_VELOCIDAD,
//    PODER_MONEDA_SALTO
//};


class Moneda : public GameObject
{
protected:
    //int valor;
    //PODER_MONEDA tipoPoderMoneda;
    //int tiempoPoderMoneda;
    Tile* tileActual;

    TextureAnimation* texturaAnimacion;

    //SDL_Rect colision;

public:

    //static const int margen = 11;

    Moneda(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY);
    ~Moneda() {};

    //int getValor() { return valor; }
    //PODER_MONEDA getTipoPoderMoneda() { return tipoPoderMoneda; }
    //int getTiempoPoderMoneda() { return tiempoPoderMoneda; }
    Tile* getTile() { return tileActual; }
    //SDL_Rect getColision() { return colision; };

    //void setValor(int _valor) { valor = _valor; }
    //void setTipoPoderMoneda(PODER_MONEDA _poderMoneda) { tipoPoderMoneda = _poderMoneda; }
    //void setTiempoPoderMoneda(int _tiempoPoderMoneda) { tiempoPoderMoneda = _tiempoPoderMoneda; }
    void setTile(Tile* _tileNuevo);

    //metodos varios
    virtual void render() {};
    void borrarGameObject() override;

};