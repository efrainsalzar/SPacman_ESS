#include "FactoryPacmanClasico.h"

GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad)
{
        return new PacmanClasico(_tile, _texturaManager->getTexture("pacman"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createFantasmaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY, int _velocidad)
{
    return new FantasmaClasico(_tile, _texturaManager->getTexture("fantasma1"), _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY)
{
    return new ParedClasico(_tile, _texturaManager->getTexture("pared"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createMonedaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY)
{
    return new MonedaClasico(_tile, _texturaManager->getTexture("moneda"), _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createFrutaInstance(Tile* _tile, TextureManager* _texturaManager, int _posicionX, int _posicionY)
{
    return new FrutaClasico(_tile, _texturaManager->getTexture("fruta"), _posicionX, _posicionY);
}

