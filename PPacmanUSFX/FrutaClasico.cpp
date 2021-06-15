#include "FrutaClasico.h"

FrutaClasico::FrutaClasico(Tile* _tile, Texture* _frutaTexture, int _posicionX, int _posicionY):
	Fruta(_tile, _frutaTexture, _posicionX, _posicionY)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_frutaTexture);
	texturaAnimacion->addCuadroAnimacion("frutita", new SDL_Rect({ 0,0,25,25 }));

}

FrutaClasico::~FrutaClasico()
{
	free();
}

void FrutaClasico::update()
{
		//if (visible){
		//	i++;
		//	if (i > 100) {
		//		visible = false;
		//		i = 0;
		//	}
		//}
		//else {
		//	i++;
		//	if (i > 100) {
		//		tileActual->setFruta(nullptr);

		//		posicionX = (rand() % 40)*25;
		//		posicionY = (rand() % 32)*25; 

		//		//tileActual->setPosicionX(rand() % 40);
		//		//tileActual->setPosicionY(rand() % 32);

		//		setTile(tileActual);
		//		//tileSiguiente = tileGraph->getTileEn(tileActual->getPosicionX(), tileActual->getPosicionY());

		//		if (tileActual->getPared() != nullptr)
		//			cout << "hay pared" << endl;

		//		else {



		//		cout << tileActual->getFruta() << "-->" << posicionX << "<>" << posicionY << endl;

		//			cout << " no hay pared" << endl;
		//			visible = true;
		//			i = 0;
		//		}


		//	}
		//}
		if (contadorTiempoVisible >= tiempoVisible) {
			visible = false;
			if (contadorTiempoNoVisible >= tiempoNoVisible) {
				posicionX = (1 + rand() % Tile::anchoTile);
				posicionY = (1 + rand() % Tile::altoTile);
				contadorTiempoVisible = 0;
				contadorTiempoNoVisible = 0;
				visible = true;
				//numeroFrutaVisible = rand() % frutasTextures.size();
				//numeroFrutaVisible = rand() % 4;
			}
			else {
				contadorTiempoNoVisible++;
				//contadorTiempoNoVisible = contadorTiempoNoVisible + 1;
			}
		}
		else {
			contadorTiempoVisible++;
		}

}

void FrutaClasico::render()
{
	
	SDL_Rect* cuadroAnimacion = new SDL_Rect();
	cuadroAnimacion = texturaAnimacion->getCuadrosAnimacion("frutita")[numeroFrame];
	texturaAnimacion->getTexture()->render(getPosicionX(), getPosicionY(), cuadroAnimacion);
}
