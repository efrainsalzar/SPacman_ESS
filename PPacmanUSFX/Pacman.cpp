#include <stdio.h>
#include "Pacman.h"
Pacman::Pacman(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_texturaPacman, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_texturaPacman);
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));

	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 0,50,25,25 }));
	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 25,50,25,25 }));
	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 50,50,25,25 }));
	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 75,50,25,25 }));
	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 0,75,25,25 }));
	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 25,75,25,25 }));
	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 50,75,25,25 }));
	texturaAnimacion->addCuadroAnimacion("dead", new SDL_Rect({ 75,75,25,25 }));

	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);
		tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}

	direccionActual = MOVE_UP;
	direccionSiguiente = MOVE_UP;


	// Inicializa propiedade de de pacman
	velocidadPatron = _velocidadPatron;
}

void Pacman::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setPacman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}

void Pacman::handleEvent(SDL_Event* event)
{
	if (event->type == SDL_KEYDOWN && event->key.repeat == 0) {
		switch (event->key.keysym.sym)
		{
			// Move up
		case SDLK_UP: direccionSiguiente = MOVE_UP; break;

			// Move down
		case SDLK_DOWN: direccionSiguiente = MOVE_DOWN; break;

			// Move left
		case SDLK_LEFT: direccionSiguiente = MOVE_LEFT; break;

			// Move right
		case SDLK_RIGHT: direccionSiguiente = MOVE_RIGHT; break;
		}
	}
}

bool Pacman::tratarDeMover(MoveDirection _direccionNueva)
{
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

void Pacman::update()
{
	// Pac-Man Comer
	if (tileActual != nullptr && tileActual->getMoneda() != nullptr) {
		SDL_Rect* comerMoneda = new SDL_Rect({ posicionX, posicionY, ancho, alto, });

		if (revisarColision(comerMoneda, tileSiguiente->getMoneda()->getColision())) {
			tileSiguiente->getMoneda()->borrarGameObject();
		}

		//if (revisarColision(comerMoneda, tileActual->getMoneda()->getColision())) {
		//	tileActual->getMoneda()->borrarGameObject();
		//}
	}
	if (tileActual != nullptr && tileActual->getFruta() != nullptr) {
		SDL_Rect* comerFruta = new SDL_Rect({ posicionX, posicionY, ancho, alto, });

		if (revisarColision(comerFruta, tileActual->getFruta()->getColision())) {
			tileActual->getFruta()->borrarGameObject();
		}
	}

	// Animacion de pacman
	if (enMovimiento) {
		GameObject::update();
	}

	// Cambiar de tile/direccion
	if (tileSiguiente == tileActual || tileSiguiente == nullptr) {
		if (direccionSiguiente != direccionActual && tratarDeMover(direccionSiguiente))
			direccionActual = direccionSiguiente;
		else
			tratarDeMover(direccionActual);

		if (tileSiguiente == nullptr)
			enMovimiento = false;
		else
			enMovimiento = true;
	}
	else {
		switch (direccionActual)
		{
		case MOVE_UP:
			posicionY = std::max(posicionY - velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_DOWN:
			posicionY = std::min(posicionY + velocidadPatron, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_LEFT:
			posicionX = std::max(posicionX - velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_RIGHT:
			posicionX = std::min(posicionX + velocidadPatron, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}

		colision->x = posicionX;
		colision->y = posicionY;

		if ((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile)
			setTile(tileSiguiente);

		if ((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile)
			setTile(tileSiguiente);
	}
}

void Pacman::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();
	if (kill) {
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("dead")[numeroFrame];
	}
	switch (direccionActual) {
	case MOVE_UP:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("arriba")[numeroFrame];
		break;
	case MOVE_DOWN:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("abajo")[numeroFrame];
		break;
	case MOVE_LEFT:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("izquierda")[numeroFrame];
		break;
	case MOVE_RIGHT:
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("derecha")[numeroFrame];
		break;
	 	
	}

	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}

void Pacman::borrarGameObject()
{
	kill = true;
	GameObject::borrarGameObject();
	tileActual->setPacman(nullptr);
	SDL_Delay(1000);

	exit(-1);
}
