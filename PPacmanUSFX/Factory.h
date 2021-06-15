#pragma once
#include "GameObject.h"
#include "Tile.h"
class Factory
{
public:
	virtual GameObject* createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidad) = 0;
	virtual GameObject* createFantasmaInstance(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _velocidad) = 0;
	virtual GameObject* createParedInstance(Tile* _tile, Texture* _texturaPared, int _posicionX, int _posicionY) = 0;
	virtual GameObject* createMonedaInstance(Tile* _tile, Texture* _texturaMoneda, int _posicionX, int _posicionY) = 0;
	virtual GameObject* createFrutaInstance(Tile* _tile, Texture* _texturaFruta, int _posicionX, int _posicionY) = 0;
};

