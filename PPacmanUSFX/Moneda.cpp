#include "Moneda.h"

Moneda::Moneda(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY) :
	GameObject(_monedaTextura, _posicionX, _posicionY)
{
	tileActual = _tile;
	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
	// Inicializa propiedade de de pacman
	//valor = 1;
	//tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	//tiempoPoderMoneda = 0;
}
//Moneda::~Moneda() {
//	free();
//}

void Moneda::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setMoneda(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}

void Moneda::borrarGameObject() {
	GameObject::borrarGameObject();
	tileActual->setMoneda(nullptr);

}
