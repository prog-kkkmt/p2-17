#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class PLAYER
{

public:

	float dx, dy; //ќбъ€вл€ем переменные сдвига по оси x и y
	FloatRect rect;//ќбъ€вл€ем переменную класа Rect, котора€ нужна нам чтобы заключить нашу картинку в пр€моугольник. 
	bool onGround;//ќбъ€вл€ем переменную логического дипа дл€ определени€ нахождени€ перснонажа на земле.
	Sprite sprite;//ќбъ€вл€ем переменную класса Sprite (дл€ объединени€ текстуры с пр€моугольником)
	float currentFrame;//ќбъ€вл€ем переменную вещественного типа дл€ хранени€ в ней текущего када и отрисовки анимации персонажа

	PLAYER(Texture &image);
	void update(float time, float offsetX, float offsetY);
	void Collision(int num);
};
#endif // !PLAYER_H

