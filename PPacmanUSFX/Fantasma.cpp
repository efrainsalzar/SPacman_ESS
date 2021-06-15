#include "Fantasma.h"
#include <iostream>
//using namespace std;
Fantasma::Fantasma(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _velocidad) :
	GameObject(_fantasmaTexture, _posicionX, _posicionY)
{
	tileActual = _tile;
	tileSiguiente = _tile;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		//tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
	direccionActual = MOVE_DOWN;
	direccionSiguiente = MOVE_UP;

	velocidad = _velocidad;
}

void Fantasma::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setFantasma(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}


