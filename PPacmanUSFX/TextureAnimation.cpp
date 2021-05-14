#include "TextureAnimation.h"

void TextureAnimation::addCuadroAnimacion(string _key, SDL_Rect* _cuadroAnimacion)
{
	auto emca = mapCuadrosAnimacion.find(_key);

	if (emca != mapCuadrosAnimacion.end()) {
		emca->second.push_back(_cuadroAnimacion);
	}
	else
	{
		vector<SDL_Rect*> vca;
		vca.push_back(_cuadroAnimacion);
		mapCuadrosAnimacion[_key] = vca;
	}

}
