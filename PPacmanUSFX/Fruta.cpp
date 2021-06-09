#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla):
	GameObject(_frutaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla) {

	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_frutaTextura);
	texturaAnimacion->addCuadroAnimacion("frutita", new SDL_Rect({ 0,0,25,25 }));

	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setFruta(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
		//cout << tileActual << "-->" << posicionX << "<>" << posicionY << endl;

	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	// Inicializa propiedade de la fruta
	tipoFruta = TIPO_FRUTA_GUINDA;

	visible = true;
	tiempoVisible = 100;
	tiempoNoVisible = 100;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
}




void Fruta::update()
{
	//if (visible){
	//	i++;
	//	if (i > 100) {
	//		visible = false;
	//		i = 0;
	//	}
	//}
	//else {
	//	i++;
	//	if (i > 100) {
	//		tileActual->setFruta(nullptr);

	//		posicionX = (rand() % 40)*25;
	//		posicionY = (rand() % 32)*25; 

	//		//tileActual->setPosicionX(rand() % 40);
	//		//tileActual->setPosicionY(rand() % 32);

	//		setTile(tileActual);
	//		//tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

	//		if (tileActual->getPared() != nullptr)
	//			cout << "hay pared" << endl;

	//		else {



	//		cout << tileActual->getFruta() << "-->" << posicionX << "<>" << posicionY << endl;

	//			cout << " no hay pared" << endl;
	//			visible = true;
	//			i = 0;
	//		}


	//	}
	//}
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = (1 + rand() % anchoPantalla);
			posicionY = (1 + rand() % altoPantalla);
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
			//numeroFrutaVisible = rand() % frutasTextures.size();
			//numeroFrutaVisible = rand() % 4;
		}
		else {
			contadorTiempoNoVisible++;
			//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
		}
	}
	else {
		contadorTiempoVisible++;
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

void Fruta::borrarGameObject()
{
	GameObject::borrarGameObject();
	tileActual->setFruta(nullptr);
}
