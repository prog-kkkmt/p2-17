#include "enemy.h"
#include "map.h"

void ENEMY::set(Texture &image, int x, int y) //Функция создает спрайт персонажа по передаваемой текстуре и создает прямоугольник (рамку)
{
	sprite.setTexture(image);
	rect = FloatRect(x, y, 16, 16);

	dx = 0.05;
	currentFrame = 0;
	life = true;
}

void ENEMY::update(float time, float offsetX, float offsetY) // Эта функция осуществляет синхронизацию со временем, реализацию функции коллизии, а также реализует анимацию персонажа.
{
	rect.left += dx * time;

	Collision();


	currentFrame += time * 0.005;
	if (currentFrame > 2) currentFrame -= 2;

	sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, 16, 16)); //Определяет анимацию противника.
	if (!life) sprite.setTextureRect(IntRect(58, 0, 16, 16)); //Определяет анимацию противника после победы героя над ним.


	sprite.setPosition(rect.left - offsetX, rect.top - offsetY); // Установка спрайта противника по заданным координатам.

}

void ENEMY::Collision() //Функция проверки столкновения противника с трубами и нахождения на земле, а также столкновения с героем.
{

	for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++) // Цил проходящий по объектам карты
		for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
			if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0')) // Условие нахождения объекта на карте с соответствующими ключами
			{
				if (dx > 0) //Условие движения противника вправо.
				{
					rect.left = j * 16 - rect.width; //Определение точки столкновения
					dx *= -1; // Осуществляет блуждание персонажа вперед и назад, отталкивающегося от объектов.
				}
				else if (dx < 0) // Условие движения персонажа влевл.
				{
					rect.left = j * 16 + 16;  
					dx *= -1;
				}
			}
}