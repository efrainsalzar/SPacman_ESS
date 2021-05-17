#include "MapGenerator.h"

MapGenerator::MapGenerator(TileGraph* _tileGraph, TextureManager* _textureManager, int _anchoPantalla, int _altoPantalla)
{
	tileGraph = _tileGraph;
	textureManager = _textureManager;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		for (unsigned int x = 0; x < chars.size(); x++) {
			GameObject* objetoNuevo = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x':
				objetoNuevo = new Pared(tileNuevo, textureManager->getTexture("pared"), x * Tile::altoTile, y * Tile::altoTile, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case '.':
				objetoNuevo = new Moneda(tileNuevo, textureManager->getTexture("moneda"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 's':
				objetoNuevo = new Moneda(tileNuevo, textureManager->getTexture("superMoneda"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(4);
				break;
			case 'p':
				objetoNuevo = new Pacman(tileNuevo, textureManager->getTexture("pacman"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 3);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'B':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma1"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'C':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma2"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'I':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma3"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'P':
				objetoNuevo = new Fantasma(tileNuevo, textureManager->getTexture("fantasma4"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				objetoNuevo->setParametrosAnimacion(2);
				break;
			case 'f':
				objetoNuevo = new Fruta(tileNuevo, textureManager->getTexture("fruta"), x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				objetoNuevo->setParametrosAnimacion(1);
				break;
			}

			// If the object was created, add it to the vector
			if (objetoNuevo != nullptr) {
				vectorObjetosJuego.push_back(objetoNuevo);
			}
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*>& _vectorObjetosJuegoGM)
{
	/*for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}*/

	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}

}