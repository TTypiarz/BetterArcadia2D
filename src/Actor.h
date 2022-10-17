#pragma once
#include "IActor.h"
#include "Transform.h"
#include <SDL.h>

struct Properties {

public:
	/// <summary>
	/// Create a new poperty to store datas about the game object
	/// </summary>
	/// <param name="textureID">The id which refers to the text</param>
	/// <param name="x">Coordinates in X of the game object</param>
	/// <param name="y">Coordinates in Y of the game object</param>
	/// <param name="width">The width of the game object</param>
	/// <param name="height">The width of the game boject</param>
	/// <param name="flip">If the object is flip or not</param>
	Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {
		X = x;
	    Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}


public:
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;
};


class Actor : public IActor
{
public:
	/// <summary>
	///  For create a new Actor
	/// </summary>
	/// <param name="prop">The property of the actors</param>
	Actor(Properties prop)//@Creater Why use pointer if it was for only one value (or it can be at mutliple place in same time ??), and why use orther arg if all of it was in the porp ???
	{
		m_transform = new Transform(prop.X, prop.Y);
		m_Flip = prop.Flip;
		m_TextureID = prop.TextureID;
		m_Height = prop.Height;
		m_Width = prop.Width;
	}

	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float dt) = 0;

protected:
	Transform* m_transform;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;


};
