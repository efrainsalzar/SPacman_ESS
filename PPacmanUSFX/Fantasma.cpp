#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Tile* _tile, Texture* _fantasmaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	GameObject(_fantasmaTextura,_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	if (tileActual != nullptr) {
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = _posicionX;
		posicionY = _posicionY;
	}

	//numeroFrame = 0;
	//contadorFrames = 0;
	velocidadPatron = _velocidadPatron;

	Pxi = posicionX;
	Pyi = posicionY;
	//Pf = 1+rand() % (1-0);
	//if (Pf % 2 == 0) {	
		sw = true; 
		Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
	//}
	//else { 
	//	sw = false;
	//	Pf = rand() % ((altoPantalla - alto)+ 1);
	//	cout << Pf<<endl;
	//}
}
	


void Fantasma::update()
{

	if (sw)
	{
		//vistaY = 25;
		if (Pxi < Pf) //derecha
		{
			posicionX += velocidadPatron;
			Pxi = getPosicionX();
			//vistaX = 0;
			if (Pxi >= Pf)
			{
				Pxi = Pf;
				Pf = rand() % ((altoPantalla - alto) - 0 + 1) + 0; //formula
				sw = false;
			}
		}
		if (Pxi > Pf) //izquierda
		{
			posicionX -= velocidadPatron;
			Pxi = getPosicionX();
			//vistaX = 50;
			if (Pxi <= Pf)
			{
				Pxi = Pf;
				Pf = rand() % ((altoPantalla - alto) - 0 + 1) + 0; //formula
				sw = false;
			}
		}
		if (Pxi == Pf )
		{
			Pxi = Pf;
			Pf = rand() % ((altoPantalla - alto) - 0 + 1) + 0; //formula
			sw = false;
		}
	}
	else
	{
		//vistaY = 0;
		if (Pyi < Pf)  //abajo
		{
			posicionY += velocidadPatron;
			Pyi = getPosicionY();
			//vistaX = 50;
			if (Pyi >= Pf)
			{
				Pyi = Pf;
				Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
				sw = true;
			}

		}
		if (Pyi > Pf) //arriba
		{
			posicionY -= velocidadPatron;
			Pyi = getPosicionY();
			//vistaX = 0;
			if (Pyi <= Pf)
			{
				Pyi = Pf;
				Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
				sw = true;
			}
		}
		if (Pyi == Pf)
		{
			Pyi = Pf;
			Pf = rand() % ((anchoPantalla - ancho) - 0 + 1) + 0; //formula
			sw = true;
		}
	}
}

void Fantasma::setTile(Tile* _tileNuevo) {
	if (tileActual != nullptr)
		tileActual->setFantasma(nullptr);

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setFantasma(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
};