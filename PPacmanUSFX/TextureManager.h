#pragma once
#include<map>
#include "Texture.h"
using namespace std;

class TextureManager
{
private:
	map<string, Texture*> mapTexturas;

	//const string pathPacman = "Resources/PacMan.bmp";
	const string pathPacman = "Resources/Pacman 2.1.png";
	//const string pathFantasma1 = "Resources/Blinky.bmp";
	const string pathFantasma1 = "Resources/Fantasma 2.1.png";
	const string pathFantasma2 = "Resources/Clyde.bmp";
	const string pathFantasma3 = "Resources/Inkey.bmp";
	const string pathFantasma4 = "Resources/Pinky.bmp";
	const string pathFruta = "Resources/Frutas.bmp";
	const string pathMoneda = "Resources/moneda2.1.bmp";
	const string pathSuperMoneda = "Resources/moneda3.bmp";
	const string pathPared = "Resources/wall4.png";

	const string pathPortal = "Resources/portal1.png";

	Texture* pacmanTexture;
	Texture* fantasma1Texture;
	Texture* fantasma2Texture;
	Texture* fantasma3Texture;
	Texture* fantasma4Texture;
	Texture* frutaTexture;
	Texture* monedaTexture;
	Texture* superMonedaTexture;
	Texture* paredTexture;

	Texture* portalTexture;
public:
	TextureManager();
	~TextureManager();

	Texture* getTexture(string _key) { return mapTexturas[_key]; }
	void addTexture(string _key, Texture* _texture);
	void free();


};

