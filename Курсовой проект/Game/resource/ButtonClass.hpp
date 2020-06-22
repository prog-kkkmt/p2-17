#pragma once 

#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//Класс кнопок
class Button
{
private:
	float x, y, dx, dy, w, h; //Координаты начальных точек, конечных и расположения спрайта
	string File;				//Имя файла
	Image image;				//объект изображения
	Texture texture;			//Объкт текстуры
public:
	Sprite sprite;				//объет спрайта

	Button(string F, float X, float Y, float W, float H, float dX, float dY)
	{
		File = F;
		w = W; h = H;	
		x = X; y = Y;
		dx = dX; dy = dY;
		image.loadFromFile("images/" + File); 		//Загрузка изображения
		texture.loadFromImage(image); 				//Создание техстуры
		sprite.setTexture(texture); 				//Создание спрайта
		sprite.setTextureRect(IntRect(x, y, w, h)); // Установка границы рисуемого спрайта
		sprite.setPosition(dx, dy); 				//Задание позиции спрайта
	}

};