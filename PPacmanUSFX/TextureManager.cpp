#include "TextureManager.h"

TextureManager::TextureManager()
{
	pacmanTexture = new Texture();
	pacmanTexture->loadFromImage(pathPacman);
	addTexture("pacman", pacmanTexture);
	fantasma1Texture = new Texture();
	fantasma1Texture->loadFromImage(pathFantasma1);
	addTexture("fantasma1", fantasma1Texture);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasma2);
	addTexture("fantasma2", fantasma2Texture);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasma3);
	addTexture("fantasma3", fantasma3Texture);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasma4);
	addTexture("fantasma4", fantasma4Texture);
	frutaTexture = new Texture();
	frutaTexture->loadFromImage(pathFruta);
	addTexture("fruta", frutaTexture);
	monedaTexture = new Texture();
	monedaTexture->loadFromImage(pathMoneda);
	addTexture("moneda", monedaTexture);
	superMonedaTexture = new Texture();
	superMonedaTexture->loadFromImage(pathSuperMoneda);
	addTexture("superMoneda", superMonedaTexture);
	paredTexture = new Texture();
	paredTexture->loadFromImage(pathPared);
	addTexture("pared", paredTexture);
}

TextureManager::~TextureManager() {
	free();
}

void TextureManager::addTexture(string _key, Texture* _texture)
{
	mapTexturas[_key] = _texture;
}

void TextureManager::free()
{
	//for (auto elementoMapTexturas : mapTexturas) {
	for (pair<string, Texture*> elementoMapTexturas : mapTexturas) {
		//delete elementoMapTexturas.second;
		mapTexturas.erase(elementoMapTexturas.first);
	}
}
