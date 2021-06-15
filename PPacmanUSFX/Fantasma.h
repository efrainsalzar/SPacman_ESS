#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <algorithm>

#include "GameObject.h"
#include "Texture.h"
#include "Tile.h"
#include "TileGraph.h"
#include "MoveDirection.h"
#include "TextureAnimation.h"
#include "PathFinder.h"
#include "Pacman.h"


using namespace std;

class Fantasma : public GameObject {
protected:
	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidad;

	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	TextureAnimation* texturaAnimacion;

	//bool Avanzar(MoveDirection _direccionNueva) {};

public:
	//Constructores y destructores
	Fantasma(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _velocidad);
	//~Fantasma();

	//Metodos accesores


	int getVelocidadPatron() { return velocidad; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }

	void setVelocidadPatron(int _velocidad) { velocidad = _velocidad; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileNuevoSiguiente) { tileSiguiente = _tileNuevoSiguiente; }

	// Metodos varios


	// Actualizar datos fantasma
	virtual void update() {};
	virtual void render() {};

	//virtual bool AvoidInPathFinder(Tile* _tile) {};
};