#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_fantasmaTexture, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_fantasmaTexture);
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 50,25,25,25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 75,25,25,25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0,25,25,25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25,25,25,25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 0,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 25,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75,0,25,25 }));

	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}
	direccionActual = MOVE_DOWN;
	direccionSiguiente = MOVE_UP;

	Pxi = posicionX;
	Pyi = posicionY;
	sw = false;
	Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
	velocidadPatron = _velocidadPatron;
}

void Fantasma::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setFantasma(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}

bool Fantasma::Avanzar(MoveDirection _direccionNueva) {
	

	Tile* tileDestino = nullptr;

	// Retorna el tile destino dependiendo de la direccion de movimiento

	switch (_direccionNueva)
	{
	case MOVE_UP:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() - 1);
		break;
	case MOVE_DOWN:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY() + 1);
		break;
	case MOVE_LEFT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() - 1, tileActual->getPosicionY());
		break;
	case MOVE_RIGHT:
		tileDestino = tileGraph->getTileEn(tileActual->getPosicionX() + 1, tileActual->getPosicionY());
		break;
	}
	// Si el tile destino es nullptr, no se puede avanzar ahi
	if (tileDestino == nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	// Si el tile destino es una pared, no se puede avanzar ahi
	if (tileDestino->getPared() != nullptr) {
		setTileSiguiente(nullptr);
		return false;
	}

	setTileSiguiente(tileDestino);
	return true;
}

void Fantasma::update()
{
	if (enMovimiento) {
		GameObject::update();
	}
	else {
		direccionSiguiente = MoveDirection(rand() % 6);
	}

	// Cambiar de tile/direccion
	if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && Avanzar(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			Avanzar(direccionActual);

		if (tileSiguiente == nullptr)
			enMovimiento = false;

		else
			enMovimiento = true;
	}
	else {
		switch (direccionActual)
		{
		case MOVE_UP:
			posicionY = max(posicionY - velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_DOWN:
			posicionY = min(posicionY + velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_LEFT:
			posicionX = max(posicionX - velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_RIGHT:
			posicionX = min(posicionX + velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}

		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);
	}


	//if (sw)
	//{
	//	if (Pxi < Pf) //derecha
	//	{
	//		posicionX += velocidadPatron;
	//		Pxi = getPosicionX();
	//		direccionActual = MOVE_RIGHT;

	//		if (Pxi >= Pf)
	//		{
	//			Pxi = Pf;
	//			Pf = rand() % ((altoPantalla - alto) - 0 + 1) + 0; //formula
	//			sw = false;
	//		}
	//	}
	//	if (Pxi > Pf) //izquierda
	//	{
	//		posicionX -= velocidadPatron;
	//		Pxi = getPosicionX();
	//		direccionActual = MOVE_LEFT;
	//		if (Pxi <= Pf)
	//		{
	//			Pxi = Pf;
	//			Pf = rand() % ((altoPantalla - alto) - 0 + 1) + 0; //formula
	//			sw = false;
	//		}
	//	}
	//	if (Pxi == Pf)
	//	{
	//		Pxi = Pf;
	//		Pf = rand() % ((altoPantalla - alto) - 0 + 1) + 0; //formula
	//		sw = false;
	//	}
	//}
	//else
	//{
	//	if (Pyi < Pf)  //abajo
	//	{
	//		posicionY += velocidadPatron;
	//		Pyi = getPosicionY();
	//		direccionActual = MOVE_DOWN;
	//		if (Pyi >= Pf)
	//		{
	//			Pyi = Pf;
	//			Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
	//			sw = true;
	//		}

	//	}
	//	if (Pyi > Pf) //arriba
	//	{
	//		posicionY -= velocidadPatron;
	//		Pyi = getPosicionY();
	//		direccionActual = MOVE_UP;
	//		if (Pyi <= Pf)
	//		{
	//			Pyi = Pf;
	//			Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
	//			sw = true;
	//		}
	//	}
	//	if (Pyi == Pf)
	//	{
	//		Pyi = Pf;
	//		Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
	//		sw = true;
	//	}
	//}


}
void Fantasma::render() 
{
	SDL_Rect* cuadroDeAnimacion = new SDL_Rect();
	switch(direccionActual)
	{
	case MOVE_UP:
		cuadroDeAnimacion = texturaAnimacion->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_DOWN:
		cuadroDeAnimacion = texturaAnimacion->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_LEFT:
		cuadroDeAnimacion = texturaAnimacion->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_RIGHT:
		cuadroDeAnimacion = texturaAnimacion->getCuadrosAnimacion("derecha")[numeroFrame];
		break;
	}
	texturaAnimacion->getTexture()->render(getPosicionX(),getPosicionY(),cuadroDeAnimacion);
}