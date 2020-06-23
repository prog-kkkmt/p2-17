#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class Player
{

public:

	float dx, dy; // Переменныесдвига по оси x и y
	// Переменная для заключения нашей картинки в прямоугольник.
	FloatRect rect; 
	// Переменная для определения нахождения перснонажа на земле.
	bool onGround;
	// Переменная для объединения текстуры с прямоугольником
	Sprite sprite;
	// Переменная для хранения текущего кадра 
	//и отрисовки анимации персонажа
	float currentFrame;

	Player(Texture &image);
	void Update(float time, float offsetX, float offsetY);
	void Collision(int num);
};
#endif // PLAYER_H

