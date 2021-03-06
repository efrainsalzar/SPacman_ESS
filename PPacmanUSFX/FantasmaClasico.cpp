#include "FantasmaClasico.h"

FantasmaClasico::FantasmaClasico(Tile* _tile, Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _velocidad):
	Fantasma(_tile, _fantasmaTexture, _posicionX, _posicionY, _velocidad)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_fantasmaTexture);
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0,50,25,25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25,50,25,25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 0,75,25,25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 25,75,25,25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 0,25,25,25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 25,25,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 50,25,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 75,25,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0,25,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25,25,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 0,0,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 25,0,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50,0,25,25 }));
	//texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75,0,25,25 }));

}

bool FantasmaClasico::avanzar(MoveDirection _direccionNueva) {


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

void FantasmaClasico::update()
{
	Pacman* pacman = tileGraph->getPacman();



	if (pacman != nullptr) {
		GameObject::update();

		// The NPC will calculate a new camino every time it has entered a new tile
		// In this way, it will dynamically follow Pacman
		if (tileActual == tileSiguiente) {
			// Get a camino to Pacman using A* algorithm
			PathFinder astar(tileGraph);
			astar.SetAvoidFunction(FantasmaClasico::AvoidInPathFinder);
			camino = astar.CalculateRoute(tileActual, pacman->getTile());

			if (camino.size() > 1)
				tileSiguiente = camino[1];

			// All we really want to do after this is check the direction the NPC should go
			if (posicionX < tileSiguiente->getPosicionX() * Tile::anchoTile)
				direccionActual = MOVE_RIGHT;

			else if (posicionX > tileSiguiente->getPosicionX() * Tile::anchoTile)
				direccionActual = MOVE_LEFT;

			else if (posicionY > tileSiguiente->getPosicionY() * Tile::anchoTile)
				direccionActual = MOVE_UP;

			else if (posicionY < tileSiguiente->getPosicionY() * Tile::anchoTile)
				direccionActual = MOVE_DOWN;

			// Check if Fantasma collides with Pacman, if so delete Pacman
			// TODO: There should be a Kill() method within Pacman, which will play death animation
			//for (auto tile : tileGraph->get4Vecinos(tileActual)) {
			//	if (tile->getPacman() != nullptr && revisarColision(tile->getPacman()->getColision())) {
			//		cout << "kill" << endl;
			//		tile->getPacman()->borrarGameObject();
			//	}
			//}
			if (revisarColision(pacman->getColision())) {
				cout << "kill" << endl;
				pacman->setDead(true);
			}

		}

		switch (direccionActual)
		{
		case MOVE_UP:
			posicionY = max(posicionY - velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;

		case MOVE_DOWN:
			posicionY = min(posicionY + velocidad, tileSiguiente->getPosicionY() * Tile::altoTile);
			break;
		case MOVE_LEFT:
			posicionX = max(posicionX - velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		case MOVE_RIGHT:
			posicionX = min(posicionX + velocidad, tileSiguiente->getPosicionX() * Tile::anchoTile);
			break;
		}

		colision->x = posicionX;
		colision->y = posicionY;

		if (((direccionActual == MOVE_DOWN || direccionActual == MOVE_UP) && posicionY == tileSiguiente->getPosicionY() * Tile::altoTile) ||

			((direccionActual == MOVE_LEFT || direccionActual == MOVE_RIGHT) && posicionX == tileSiguiente->getPosicionX() * Tile::anchoTile))
			setTile(tileSiguiente);
	}
}

void FantasmaClasico::render()
{
	setParametrosAnimacion(2);

	SDL_Rect* cuadroDeAnimacion = new SDL_Rect();
	switch (direccionActual)
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
	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroDeAnimacion);
}

bool FantasmaClasico::AvoidInPathFinder(Tile* _tile) {
	if (_tile->getPared() != nullptr)
		return true;
	return false;
}
