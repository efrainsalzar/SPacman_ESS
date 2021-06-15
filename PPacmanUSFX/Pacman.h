#pragma once
#include <iostream>
#include <string>
#include <algorithm>

#include <SDL.h>

#include "Moneda.h"
#include "Fruta.h"
#include "Fantasma.h"

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"
#include "TextureAnimation.h" 

using namespace std;

class Pacman : public GameObject
{
protected:
	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidad;

	TextureAnimation* texturaAnimacion;

	//SDL_Rect colision;
	bool dead = false;

public:	
	//Constructores y destructores
	Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidad);
	//~Pacman();


	//Metodos accesores

	int getVelocidadPatron() { return velocidad; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }

	void setVelocidadPatron(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileSiguienteNuevo) { tileSiguiente = _tileSiguienteNuevo; }


	// Metodos varios
	//virtual bool tratarDeMover(MoveDirection _direccionNueva) {};

	virtual void handleEvent(SDL_Event* event) {};
	// Mover pacman
	virtual void update() {};
	// Renderizar imagen pacman
	virtual void render() {};
	//void update();
	virtual void borrarGameObject() override;

};

