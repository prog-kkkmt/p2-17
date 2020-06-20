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
	float dx, dy; // Переменные смещения по осям X и Y.
	FloatRect rect; // Переменная для заключения картинки в прямоугольник
	Sprite sprite; // Переменная для объединения текстуры с прямоугольником
	// Переменная хранения в ней текущего када и отрисовки анимации персонажа
	float currentFrame;
	bool life; // Переменная определяющая состояние противника.

	void set(Texture &image, int x, int y);
	void update(float time, float offsetX, float offsetY);
	void Collision();
};
#endif // ENEMY_H


