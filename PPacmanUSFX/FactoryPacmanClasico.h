#pragma once
#include "Factory.h"

#include "PacmanClasico.h"
#include "FantasmaClasico.h"
#include "ParedClasico.h"
#include "MonedaClasico.h"
#include "FrutaClasico.h"
#include "Portal.h"
class FactoryPacmanClasico :
    public Factory
{
public:
    GameObject* createPacmanInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createFantasmaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad) override;
    GameObject* createParedInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY) override;
    GameObject* createMonedaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY) override;
    GameObject* createFrutaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY) override;

    GameObject* createPortalInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY) override;


};

