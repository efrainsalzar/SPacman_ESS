#include "Moneda.h"

Moneda::Moneda(Tile* _tile, Texture* _monedaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	GameObject(_monedaTextura, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_monedaTextura);
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 0,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 25,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 50,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 75,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 100,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 125,0,25,25 }));

	tileActual = _tile;
	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}


	// Inicializa propiedade de de pacman
	//valor = 1;
	//tipoPoderMoneda = PODER_MONEDA_NINGUNO;
	//tiempoPoderMoneda = 0;
}
Moneda::~Moneda() {
	free();
}

void Moneda::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr) {
		tileActual->setMoneda(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setMoneda(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;

		//colision.x = posicionX;
		//colision.y = posicionY;
	}
}

void Moneda::render() {
	SDL_Rect* cuadroAnimacion = new SDL_Rect();
	cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("moneda")[numeroFrame];
	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}

void Moneda::borrarGameObject() {
	GameObject::borrarGameObject();
	tileActual->setMoneda(nullptr);

}
