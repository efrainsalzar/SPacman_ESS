#include "Tile.h"


Tile::Tile() {
	posicionX = 0;
	posicionY = 0;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
	portal = nullptr;
}

Tile::Tile(int _x, int _y) {
	posicionX = _x;
	posicionY = _y;

	pacman = nullptr;
	fantasma = nullptr;
	fruta = nullptr;
	moneda = nullptr;
	pared = nullptr;
	portal = nullptr;
}