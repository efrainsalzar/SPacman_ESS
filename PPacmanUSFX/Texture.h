#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class Texture
{
private:
	// Textura actual
	SDL_Texture* texture;

	int ancho;
	int alto;

public:
	// Static SDL_Renderer so we don't have to ask for it
	// when creating the texture or when rendering
	// TODO: Temporary solution, should be removed after implementation of Game class
	static SDL_Renderer* renderer;

	Texture();
	~Texture();

	// Load texture from file
	bool loadFromImage(std::string path, Uint8 r = 0, Uint8 g = 0, Uint8 b = 0);

	// Load texture from rendered text
	bool loadFromRenderedText(TTF_Font* font, std::string text, SDL_Color textColor);

	// Render the texture
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip renderFlip = SDL_FLIP_NONE);

	// Set color
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	// Set blend mode
	void setBlendMode(SDL_BlendMode blendMode);

	// Set alpha
	void setAlpha(Uint8 alpha);

	// Free assets
	void free();

	int getAncho() { return ancho; }
	int getAlto() { return alto; }
};

