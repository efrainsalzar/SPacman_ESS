#include "FactoryPacmanClasico.h"

GameObject* FactoryPacmanClasico::createPacmanInstance(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidad)
{
        return new PacmanClasico(_tile, _texturaPacman, _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createFantasmaInstance(Tile* _tile, Texture* _texturaFantasma, int _posicionX, int _posicionY, int _velocidad)
{
    return new FantasmaClasico(_tile, _texturaFantasma, _posicionX, _posicionY, _velocidad);
}

GameObject* FactoryPacmanClasico::createParedInstance(Tile* _tile, Texture* _texturaPared, int _posicionX, int _posicionY)
{
    return new ParedClasico(_tile, _texturaPared, _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createMonedaInstance(Tile* _tile, Texture* _texturaMoneda, int _posicionX, int _posicionY)
{
    return new MonedaClasico(_tile, _texturaMoneda, _posicionX, _posicionY);
}

GameObject* FactoryPacmanClasico::createFrutaInstance(Tile* _tile, Texture* _texturaFruta, int _posicionX, int _posicionY)
{
    return new FrutaClasico(_tile, _texturaFruta, _posicionX, _posicionY);
}

