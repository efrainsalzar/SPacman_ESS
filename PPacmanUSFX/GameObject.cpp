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
}

void GameObject::render()
{
	SDL_Rect renderQuad = { (25 * numeroFrame, 0, getAncho(), getAlto()) };

	// Renderizar en la pantalla
	textura->render(getPosicionX(), getPosicionY(), &renderQuad);
}

void GameObject::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}