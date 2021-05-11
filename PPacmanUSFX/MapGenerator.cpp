#include "MapGenerator.h"

MapGenerator::MapGenerator(TileGraph* _tileGraph, int _anchoPantalla, int _altoPantalla)
{
	tileGraph = _tileGraph;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	pacmanTexture = new Texture();
	pacmanTexture->loadFromImage(pathPacman);
	fantasma1Texture = new Texture();
	fantasma1Texture->loadFromImage(pathFantasmaB);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasmaC);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasmaI);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasmaP);
	frutaTexture = new Texture();
	frutaTexture->loadFromImage(pathFruta);
	monedaTexture = new Texture();
	monedaTexture->loadFromImage(pathMoneda);
	//superMonedaTexture = new Texture();
	//superMonedaTexture->loadFromImage(pathSuperMoneda);
	paredTexture = new Texture();
	paredTexture->loadFromImage(pathPared);
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
			GameObject* newObject = nullptr;
			Tile* tileNuevo = tileGraph->getTileEn(x, y);

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{
			case 'x': //Pared
				newObject = new Pared(tileNuevo, paredTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				//newObject->setParametrosAnimacion(1);
				break;
			case '.': //Moneda
				newObject = new Moneda(tileNuevo, monedaTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(1);
				break;
			case 'p': //Pacman
				newObject = new Pacman(tileNuevo, pacmanTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 2);
				newObject->setParametrosAnimacion(2);
				cout << tileNuevo->getPosicionX() << "----" << tileNuevo->getPosicionY() << endl;
				break;
			case 'B'://Blinky
				newObject = new Fantasma(fantasma1Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				newObject->setParametrosAnimacion(2);
				break;
			case 'C'://Clyde
				newObject = new Fantasma(fantasma2Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				newObject->setParametrosAnimacion(2);
				break;
			case 'I'://Inkey
				newObject = new Fantasma(fantasma3Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				newObject->setParametrosAnimacion(2);
				break;
			case 'P'://Pinky
				newObject = new Fantasma(fantasma4Texture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 1);
				newObject->setParametrosAnimacion(2);
				break;
			case'f':
				newObject = new Fruta(frutaTexture,x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				//newObject->setParametrosAnimacion(1);
				break;
			}

			// If the object was created, add it to the vector
			if (newObject != nullptr)
				vectorObjetosJuego.push_back(newObject);
		}
		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<GameObject*>& _vectorObjetosJuegoGM)
{
	//for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
	//	_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	//}

	for (auto ivoj = vectorObjetosJuego.begin(); ivoj != vectorObjetosJuego.end(); ++ivoj) {
		_vectorObjetosJuegoGM.push_back(*ivoj);
	}
}