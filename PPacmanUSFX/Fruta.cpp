#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla):
	GameObject(_frutaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla) {

	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_frutaTextura);
	texturaAnimacion->addCuadroAnimacion("frutita", new SDL_Rect({ 0,0,25,25 }));

	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	// Inicializa propiedade de la fruta
	tipoFruta = TIPO_FRUTA_GUINDA;

	visible = false;
	//Tile* tileDestino = nullptr;
}




void Fruta::update()
{

	
	if (!visible){
		//cout << "No"<< endl;
		if (i >= 100) {
			posicionX = (rand() % 40) * 25;
			posicionY = (rand() % 32) * 25;
			cout << posicionX << "<>" << posicionY << endl;
			visible = true;
			i = 0;

		}
		else
			i++;
	}
	else {
		//cout << "V" << endl;
		if (i == 0) {
			render();
			
			i++;
		}else
			if (i > 100) {
				visible = false;
				i = 0;
			}
			else
				i++;
	}

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
void Fruta::render() {
	SDL_Rect* cuadroAnimacion = new SDL_Rect();
	cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("frutita")[numeroFrame];
	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}