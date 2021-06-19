#include "Portal.h"

Portal::Portal(Tile* _tile, Texture* _portalTextura, int _posicionX, int _posicionY) :
	GameObject(_portalTextura, _posicionX, _posicionY)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_portalTextura);
	texturaAnimacion->addCuadroAnimacion("portal", new SDL_Rect({ 0, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("portal", new SDL_Rect({ 25, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("portal", new SDL_Rect({ 50, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("portal", new SDL_Rect({ 75, 0, 25, 25 }));

	tileActual = _tile;

	if (tileActual != nullptr) {
		tileActual->setPortal(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
}

void Portal::setTile(Tile* _tileNuevo)
{
	if (tileActual != nullptr)
		tileActual->setPortal(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPortal(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
}

//void Portal::update() 
//{
//	GameObject::update();
//}

void Portal::render()
{
	//cout << "portal" << endl;
	setParametrosAnimacion(4);
	SDL_Rect* cuadroAnimacion = new SDL_Rect();
	cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("portal")[numeroFrame];

	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);

}
