#include "MonedaClasico.h"

MonedaClasico::MonedaClasico(Tile* _tile, Texture* _monedaTexture, int _posicionX, int _posicionY):
	Moneda(_tile, _monedaTexture, _posicionX, _posicionY)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_monedaTexture);
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 0,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 25,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 50,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 75,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 100,0,25,25 }));
	texturaAnimacion->addCuadroAnimacion("moneda", new SDL_Rect({ 125,0,25,25 }));

}

MonedaClasico::~MonedaClasico()
{
	free();
}

void MonedaClasico::render() {
	setParametrosAnimacion(6);
	SDL_Rect* cuadroAnimacion = new SDL_Rect();
	cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("moneda")[numeroFrame];
	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}
