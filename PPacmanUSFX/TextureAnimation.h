#pragma once
#include <vector>
#include <map>
#include <string>
#include <SDL.h>
#include "Texture.h"

using namespace std;

class TextureAnimation
{
private:
	Texture* texturaAnimacion;
	map<string, vector<SDL_Rect*>> mapCuadrosAnimacion;
public:
	TextureAnimation() {};
	~TextureAnimation() {};

	Texture* getTexture() { return texturaAnimacion; }
	vector<SDL_Rect*> getCuadrosAnimacion(string _key) { return mapCuadrosAnimacion[_key]; }

	void setTexture(Texture* _textura) { texturaAnimacion = _textura; }
	void setCuadrosAnimacion(string _key, vector<SDL_Rect*> _vectorCuadrosAnimacion) {
		mapCuadrosAnimacion[_key] = _vectorCuadrosAnimacion;
	}
	void addCuadroAnimacion(string _key, SDL_Rect* _cuadroAnimacion);
};

