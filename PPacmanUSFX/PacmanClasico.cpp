#include "PacmanClasico.h"

PacmanClasico::PacmanClasico(Tile* _tile, Texture* _texturePacman, int _posicionX, int _posicionY, int _velocidad) :
	Pacman(_tile, _texturePacman, _posicionX, _posicionY, _velocidad)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_texturePacman);
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

}

//void PacmanClasico::deadPacman()
//{
//	SDL_Rect* cuadroAnimacion = new SDL_Rect();
//
//
//
//	cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("dead")[numeroFrame];
//}


void PacmanClasico::handleEvent(SDL_Event* event)
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

bool PacmanClasico::tratarDeMover(MoveDirection _direccionNueva)
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


void PacmanClasico::update()
{	
	// Animacion de pacman
	//if (enMovimiento) {
		GameObject::update();
	//}
	if (dead)
	{
		tileActual->setPacman(nullptr);
		kill++;
		if (kill >= 55)
		{
			borrarGameObject();
		}
	}
	else
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


		//deadPacman();

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
				posicionY = std::max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
				break;
			case MOVE_DOWN:
				posicionY = std::min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
				break;
			case MOVE_LEFT:
				posicionX = std::max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
				break;
			case MOVE_RIGHT:
				posicionX = std::min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
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

}


void PacmanClasico::render()
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();
	if (!dead) {
		setParametrosAnimacion(2);
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
	else {
		setParametrosAnimacion(8);
		cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("dead")[numeroFrame];
		texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
	}
}
