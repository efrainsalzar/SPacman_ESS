#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"
#include "TileGraph.h"

using namespace std;

class Fantasma : public GameObject {
private:
	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	bool sw;
	int Pxi; int  Pf; int Pyi;
	Tile* tileActual;

public:
	Fantasma(Tile* _tile, Texture* _fantasmaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//~Fantasma();
	

	//Metodos accesores
	int getVelocidadPatron() { return velocidadPatron; }
	Tile* getTile() { return tileActual; }

	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setTile(Tile* tileNuevo);

	
		
	// Mover fantasma
	void update();
};