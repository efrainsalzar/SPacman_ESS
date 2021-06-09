#include "TileGraph.h"

TileGraph::TileGraph()
{
	//tiles = nullptr;

	anchoTileGraph = 0;
	altoTileGraph = 0;
}

TileGraph::TileGraph(int _anchoTileGraph, int _altoTileGraph)
{
	for (int y = 0; y < _altoTileGraph; y++) {
			for (int x = 0; x < _anchoTileGraph; x++) {
				vectorTilesGraph.push_back(new Tile(x, y));
			}

	}

	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

void TileGraph::reconfigurar(int _anchoTileGraph, int _altoTileGraph)
{
	if (!vectorTilesGraph.empty())
		vectorTilesGraph.clear();

	// Establece la posicion de todos los tiles
	for (int y = 0; y < _altoTileGraph; y++) {
			for (int x = 0; x < _anchoTileGraph; x++) {
				vectorTilesGraph.push_back(new Tile(x, y));
			}
	}

	anchoTileGraph = _anchoTileGraph;
	altoTileGraph = _altoTileGraph;
}

TileGraph::~TileGraph()
{
	vectorTilesGraph.clear();
}

int TileGraph::getIndice(int x, int y)
{
	if (x >= anchoTileGraph || y >= altoTileGraph)
		return -1;

	if (x < 0 || y < 0)
		return -1;

	return x + y * anchoTileGraph;
}

Tile* TileGraph::getTileEn(int _x, int _y)
{
	int indice = getIndice(_x, _y);
	if (indice < 0)
		return nullptr;

	return vectorTilesGraph[indice];
}

array<Tile*, 4> TileGraph::get4Vecinos(Tile* _tile)
{
	array<Tile*, 4> vecinos;

	int x = _tile->getPosicionX();
	int y = _tile->getPosicionY();

	vecinos[0] = getTileEn(x, y + 1);		// N
	vecinos[1] = getTileEn(x + 1, y);		// E
	vecinos[2] = getTileEn(x, y - 1);		// S
	vecinos[3] = getTileEn(x - 1, y);		// W

	return vecinos;
}

array<Tile*, 8> TileGraph::get8Vecinos(Tile* _tile)
{
	array<Tile*, 8> vecinos;

	int x = _tile->getPosicionX();
	int y = _tile->getPosicionY();

	vecinos[0] = getTileEn(x, y + 1);		// N
	vecinos[1] = getTileEn(x + 1, y);		// E
	vecinos[2] = getTileEn(x, y - 1);		// S
	vecinos[3] = getTileEn(x - 1, y);		// W
	vecinos[4] = getTileEn(x + 1, y + 1);	// NE
	vecinos[5] = getTileEn(x - 1, y + 1);	// SE
	vecinos[6] = getTileEn(x - 1, y - 1);	// SW
	vecinos[7] = getTileEn(x + 1, y - 1);	// NW

	return vecinos;
}

Pacman* TileGraph::getPacman()
{
	for (auto ivtg = vectorTilesGraph.begin(); ivtg != vectorTilesGraph.end(); ++ivtg) {
		if ((*ivtg)->getPacman() != nullptr) {
			return (*ivtg)->getPacman();
		}
	}


	return nullptr;
}