#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class ENEMY
{

public:
	float dx, dy; //ќбъ€вление переменных смещени€ по ос€м X и Y.
	FloatRect rect; //ќбъ€вл€ем переменную класа Rect, котора€ нужна нам чтобы заключить нашу картинку в пр€моугольник.
	Sprite sprite; //ќбъ€вл€ем переменную класса Sprite (дл€ объединени€ текстуры с пр€моугольником)
	float currentFrame; //ќбъ€вл€ем переменную вещественного типа дл€ хранени€ в ней текущего када и отрисовки анимации персонажа
	bool life; // ќбъ€вл€ем переменную логического типа определ€ющую состо€ние противника.

	void set(Texture &image, int x, int y);
	void update(float time, float offsetX, float offsetY);
	void Collision();
};
#endif // !PLAYER_H


