#include <stdio.h>
#include "Pacman.h"
Pacman::Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidad) :
	GameObject(_texturaPacman, _posicionX, _posicionY)
{	
	// Inicializa propiedades de pacman

	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	direccionActual = MOVE_UP;
	direccionSiguiente = MOVE_RIGHT;


	velocidad = _velocidad;
}

void Pacman::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setPacman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}

void Pacman::borrarGameObject()
{
	dead = true;
	//render();
	GameObject::borrarGameObject();
	tileActual->setPacman(nullptr);
	SDL_Delay(1000);

	exit(-1);
}
