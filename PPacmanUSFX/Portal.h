#pragma once
#include "GameObject.h"
#include "Tile.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "TextureAnimation.h"
#include "Pacman.h"

class Portal :
	public GameObject
{
protected:
	Tile* tileActual;
	TextureAnimation* texturaAnimacion;
public:

	Portal(Tile* _tile, Texture* _portalTextura, int _posicionX, int _posicionY);
	~Portal() {};
	Tile* getTile() { return tileActual; }
	void setTile(Tile* _tileNuevo);

	void update() override;
	void render() override;

};



