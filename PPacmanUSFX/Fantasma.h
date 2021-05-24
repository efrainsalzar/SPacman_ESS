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
private:
	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	bool sw;
	int Pxi; int  Pf; int Pyi;

	Tile* tileActual;
	Tile* tileSiguiente;

	MoveDirection direccionActual;
	MoveDirection direccionSiguiente;

	TextureAnimation* texturaAnimacion;

	bool Avanzar(MoveDirection _direccionNueva);

	vector<Tile*> camino;

public:
	//Constructores y destructores
	Fantasma(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//~Fantasma();

	//Metodos accesores


	int getVelocidadPatron() { return velocidadPatron; }
	Tile* getTile() { return tileActual; }
	Tile* getTileSiguiente() { return tileSiguiente; }

	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setTile(Tile* _tileNuevo);
	void setTileSiguiente(Tile* _tileNuevoSiguiente) { tileSiguiente = _tileNuevoSiguiente; }

	// Metodos varios


	// Actualizar datos fantasma
	void update() override;
	void render() override;
	static bool AvoidInPathFinder(Tile* _tile);
};