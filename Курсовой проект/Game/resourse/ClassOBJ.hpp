#pragma once 

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//Класс для объектов
//Полностью аналогичен классу Button
class obj
{
private:
	float x, y, dx, dy, w, h;
	string File;
	Image image;	
	Texture texture;	
public:
	Sprite sprite;	
	obj(string F, float dX, float dY, float W, float H, float X, float Y)
	{
		File = F;
		w = W; h = H;	
		x = X; y = Y;
		dx = dX; dy = dY;
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(dx, dy, w, h));
		sprite.setPosition(x, y);
	}

};
