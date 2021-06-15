#pragma once
#include "Pacman.h"
class PacmanClasico :
    public Pacman
{
private:

protected:

public:
    PacmanClasico(Tile* _tile, Texture* _texturePacman, int _posicionX, int _posicionY, int _velocidad);
    ~PacmanClasico() {};

    void deadPacman();
    bool tratarDeMover(MoveDirection _direccionNueva);

    void handleEvent(SDL_Event* event) override;
    void update() override;
    void render() override;
};

