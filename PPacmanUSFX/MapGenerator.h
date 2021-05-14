#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<string>
#include <fstream>

#include "GameObject.h"
#include "Texture.h"
#include "Moneda.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "Fruta.h"
#include "Pared.h"
#include "Tile.h"
#include "TileGraph.h"
#include "TextureManager.h"
#include "TextureAnimation.h"
using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;
	TileGraph* tileGraph;
	TextureManager* textureManager;


	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*>& _vectorObjetosJuegoGM);
};

