#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Moneda.h"
#include "Texture.h"
#include "MapGenerator.h"
#include "TileGraph.h"
#include "TextureManager.h"

using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 975;
const int SCREEN_HEIGHT = 800;

class GameManager
{
private:
    bool juego_en_ejecucion;

    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

public:
    vector<GameObject*> actoresJuego;
    MapGenerator* generadorNivelJuego;
    TextureManager* textureManager;
public:
    GameManager();
    int onExecute();
    bool onInit();
    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
};
