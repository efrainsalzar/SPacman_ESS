#pragma once
#include "Factory.h"
#include "PacmanClasico.h"
#include "FantasmaClasico.h"
#include "ParedClasico.h"
#include "MonedaClasico.h"
#include "FrutaClasico.h"
class FactoryPacmanClasico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createFantasmaInstance(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile, Texture* _texturaPared, int _posicionX, int _posicionY) override;
    GameObject* createMonedaInstance(Tile* _tile, Texture* _texturaMoneda, int _posicionX, int _posicionY) override;
    GameObject* createFrutaInstance(Tile* _tile, Texture* _texturaFruta, int _posicionX, int _posicionY) override;

};

