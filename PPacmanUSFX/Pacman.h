#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "Moneda.h"
#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"
#include "TextureAnimation.h" 

using namespace std;

class Pacman : public GameObject
{
private:
	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	TextureAnimation* texturaAnimacion;

	//SDL_Rect colision;

public:
	//Constructores y destructores
	Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//~Pacman();

	//Metodos accesores

	int getVelocidadPatron() { return velocidadPatron; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }

	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileSiguienteNuevo) { tileSiguiente = _tileSiguienteNuevo; }


	// Metodos varios
	bool tratarDeMover(MoveDirection _direccionNueva);
	//bool hayColision(const SDL_Rect& _colision, const SDL_Rect& _otraColision);
	//SDL_Rect getColision() { return colision; }
	// Manejador de eventos de pacman
	void handleEvent(SDL_Event* event) override;
	// Mover pacman
	void update() override;
	// Renderizar imagen pacman
	void render() override;
	//void update();
	void borrarGameObject() override;

};

