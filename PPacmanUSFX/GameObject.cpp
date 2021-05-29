#include "GameObject.h"

int GameObject::numeroObjetosCreados = 0;
TileGraph* GameObject::tileGraph = nullptr;

GameObject::GameObject(Texture* _textura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	eliminar = false;
	enMovimiento = false;
	numeroObjetosCreados++;
	idObjeto = numeroObjetosCreados;
	textura = _textura;
	numeroFrame = 0;
	contadorFrames = 0;
	framesMovimiento = 1;
	colision = new SDL_Rect({ _posicionX,_posicionY, _ancho, _alto });

}

void GameObject::render()
{
	SDL_Rect renderQuad = { (25 * numeroFrame, 0, getAncho(), getAlto()) };

	// Renderizar en la pantalla
	textura->render(getPosicionX(), getPosicionY(), &renderQuad);
}

bool GameObject::revisarColision( const SDL_Rect* _otraColision) 
{
	if (colision->x + colision->w < _otraColision->x)
		return false;
	if (colision->y + colision->h < _otraColision->y)
		return false;
	if (_otraColision->x + _otraColision->w < colision->x)
		return false;
	if (_otraColision->y + _otraColision->h < colision->y)
		return false;
	
	return true;
}

bool GameObject::revisarColision(const SDL_Rect* _colision1, const SDL_Rect* _colision2) 
{
	if (_colision2->x + _colision2->w < _colision1->x)
		return false;
	if (_colision2->y + _colision2->h < _colision1->y)
		return false;
	if (_colision1->x + _colision1->w < _colision2->x)
		return false;
	if (_colision1->y + _colision1->h < _colision2->y)
		return false;

	return true;
}

void GameObject::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}
