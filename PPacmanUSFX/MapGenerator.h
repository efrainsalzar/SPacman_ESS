#pragma once
#include<iostream>
#include<vector>
#include <list>
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


using namespace std;

class MapGenerator
{
private:
	vector<GameObject*> vectorObjetosJuego;
	TileGraph* tileGraph;

	const string pathPacman = "Resources/PacMan.bmp";
	const string pathFantasmaB = "Resources/Blinky.bmp";
	const string pathFantasmaC = "Resources/Clyde.bmp";
	const string pathFantasmaI = "Resources/Inkey.bmp";
	const string pathFantasmaP = "Resources/Pinky.bmp";
	const string pathFruta = "Resources/fruta1.bmp";
	const string pathMoneda = "Resources/point.bmp";
	//const string pathSuperMoneda = "Resources/Monedas03.jpg";
	const string pathPared = "Resources/wall.bmp";

	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;

	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(TileGraph* _tileGraph, int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<GameObject*>& _vectorObjetosJuegoGM);
};

