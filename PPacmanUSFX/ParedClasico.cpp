#include "ParedClasico.h"

ParedClasico::ParedClasico(Tile* _tile, Texture* _paredTexture, int _posicionX, int _posicionY):
	Pared(_tile, _paredTexture, _posicionX, _posicionY)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_paredTexture);
	texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 0, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 0, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 25, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 25, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 25, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 25, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 25, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 0, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 0, 0, 25, 25 }));
	//texturaAnimacion->addCuadroAnimacion("pared", new SDL_Rect({ 0, 0, 25, 25 }));
}

void ParedClasico::formaPared() {
}

void ParedClasico::render() 
{
	SDL_Rect* cuadroAnimacion = new SDL_Rect();

	cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("pared")[numeroFrame];

	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
};