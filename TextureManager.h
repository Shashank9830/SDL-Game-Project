#pragma once

#ifndef __TextureManager__
#define __TextureManager__

#include "SDL.h"
#include "SDL_image.h"
#include <map>	//for std::map

class TextureManager
{
	std::map<std::string, SDL_Texture*> m_textureMap;
	
	static TextureManager* s_pInstance;
	
	TextureManager() {}
	~TextureManager(){}

public:

	bool load(std::string fileName, std::string id, SDL_Renderer *pRenderer);

	//draw
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//drawFrame
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Instance function
	static TextureManager *Instance()
	{
		if (s_pInstance == NULL)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	//function to remove a texture with specific texture ID
	void clearFromTextureMap(std::string id);
};
typedef TextureManager TheTextureManager;

#endif /* defined(__TextureManager__)*/