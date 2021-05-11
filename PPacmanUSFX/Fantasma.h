#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "GameObject.h"
#include "Texture.h"

using namespace std;

class Fantasma : public GameObject{
private:
	//Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;

	bool sw;
	int Pxi; int  Pf; int Pyi;

public:
	//Constructores y destructores
	//Fantasma(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Texture* _fantasmaTexture,int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//Fantasma(string path, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	Fantasma(Texture* _fantasmaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);
	//~Fantasma();
	
	//Metodos accesores


	int getVelocidadPatron() { return velocidadPatron; }

	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	
		
	// Mover fantasma
	void update();
};