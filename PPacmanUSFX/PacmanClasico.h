#pragma once
#include "Pacman.h"
class PacmanClasico :
    public Pacman
{
private:
    int kill = 0;
protected:

public:
    PacmanClasico(Tile* _tile, Texture* _texturePacman, int _posicionX, int _posicionY, int _velocidad);
    ~PacmanClasico() {};

    //void getDead() { return dead; };
    //void setDead(bool _dead) { dead = _dead; }
    bool tratarDeMover(MoveDirection _direccionNueva);

    //void deadPacman();

    void handleEvent(SDL_Event* event) override;
    void update() override;
    void render() override;
};

