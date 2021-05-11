#pragma once
#include <iostream>
#include <string>
#include "Texture.h"

using namespace std;

class TileGraph;

class GameObject
{
public:
	string nombre;
	static TileGraph* tileGraph;
	static int numeroObjetosCreados;
protected:
	// Posicion en el eje X y Y
	int idObjeto;
	int posicionX;
	int posicionY;

	// Ancho y Alto de la imagen del objeto en pixeles
	int ancho;
	int alto;

	// Ancho y alto de la pantalla del juego
	int anchoPantalla;
	int altoPantalla;

	// Si el objeto es visible
	//bool visible;
	bool eliminar;
	bool visible;
	bool enMovimiento;

	// Textura para representacion grafica del objeto
	Texture* textura;

	int numeroFrame;
	int contadorFrames;
	int framesMovimiento;
	int vistaX = 0; int vistaY = 0;

public:
	//Constructores y destructores
	GameObject(Texture* _textura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

	//Metodos accesores
	int getIdObjeto() { return idObjeto; }
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible; }
	bool getEliminar() { return eliminar; }
	bool getEnMovimiento() { return enMovimiento; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setEliminar(bool _eliminar) { eliminar = _eliminar; }
	void eliminarGameObject() { eliminar = true; }
	void setEnMovimiento(bool _enMovimiento) { enMovimiento = _enMovimiento; }

	// Metodos varios
	void setParametrosAnimacion(int _framesMovimiento) { framesMovimiento = _framesMovimiento; }
	// Renderizar imagen
	virtual void render();
	virtual void update();
	virtual void handleEvent(SDL_Event* event) {};
	//virtual void move() {};
	//virtual void mostrar() {};

};