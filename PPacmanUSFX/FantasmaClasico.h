#pragma once
#include "Fantasma.h"
#include "PathFinder.h"

class FantasmaClasico :
    public Fantasma
{
//private:
protected:
    vector<Tile*> camino;
    bool avanzar(MoveDirection _direccionNueva);

public:
    FantasmaClasico(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _velocidad);

    void render() override;
    void update() override;

    static bool AvoidInPathFinder(Tile* _tile);

};

