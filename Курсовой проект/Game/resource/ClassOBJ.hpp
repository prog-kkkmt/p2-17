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
	float x, y, dx, dy, w, h; //Переменные координат, начальной точки по х и по у, высоты, ширины
	string File;	//Имя файла
	Image image;		//объект изображения
	Texture texture;	//Объект текстуры
public:
	Sprite sprite;		//объет спрайта
	obj(string F, float dX, float dY, float W, float H, float X, float Y)
	{
		File = F;
		w = W; h = H;	
		x = X; y = Y;
		dx = dX; dy = dY;
		image.loadFromFile("images/" + File);			//создание изображения
		texture.loadFromImage(image);					//создание текстуры
		sprite.setTexture(texture);						//создание спрайта
		sprite.setTextureRect(IntRect(dx, dy, w, h));	//обрезка спрайта до нужной области
		sprite.setPosition(x, y);						//установка позиции спрайта
	}

};
