#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>

#include "GameObject.h"
#include "TileGraph.h"
#include "Tile.h"
#include "Texture.h"
#include "TextureAnimation.h"

using namespace std;

enum TIPO_FRUTA {
	TIPO_FRUTA_GUINDA,
	TIPO_FRUTA_FRUTILLA,
	TIPO_FRUTA_NARANJA,
	TIPO_FRUTA_PLATANO,
	TIPO_FRUTA_MANZANA,
	TIPO_FRUTA_MAXIMO
};


class Fruta : public GameObject
{
private:
	int i = 0;
	int contadorTiempoVisible;
	int contadorTiempoNoVisible;
	int tiempoVisible;
	int tiempoNoVisible;

	TIPO_FRUTA tipoFruta;

	Tile* tileActual;
	Tile* tileSiguiente;

	TextureAnimation* texturaAnimacion;

public:
	//Constructores y destructores
	Fruta(Tile* _tile, Texture* _frutaTextura, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	~Fruta() {};

	//Metodos accesores

	TIPO_FRUTA getTipoFruta() { return tipoFruta; }
	Tile* getTile() { return tileActual; }

	void setTipoFruta(TIPO_FRUTA _tipoFruta) { tipoFruta = _tipoFruta; }
	void setTile(Tile* tileNuevo);

	// Metodos varios
	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);
	
	// Mostrar u ocultar fruta
	void update() override;
	// Renderizar imagen fruta
	void render();

	void borrarGameObject() override;

};

