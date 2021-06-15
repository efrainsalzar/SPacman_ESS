#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY):
	GameObject(_frutaTextura, _posicionX, _posicionY) {


	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
		//cout << tileActual << "-->" << posicionX << "<>" << posicionY << endl;

	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	// Inicializa propiedade de la fruta
	tipoFruta = TIPO_FRUTA_GUINDA;

	visible = true;
	tiempoVisible = 100;
	tiempoNoVisible = 100;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
}

void Fruta::setTile(Tile* _tileNuevo){
	if (tileActual != nullptr)
		tileActual->setFruta(nullptr);
	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);
		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}

void Fruta::borrarGameObject()
{
	GameObject::borrarGameObject();
	tileActual->setFruta(nullptr);
}
