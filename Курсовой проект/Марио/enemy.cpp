#include "enemy.h"
#include "map.h"

// Ширина, и высота используемой рамки
const int size = 16;
// Степень уменьшения скорости анимации
const double period = 0.005;

// Функция создает спрайт персонажа по передаваемой 
// текстуре и создает прямоугольник (рамку)
void Enemy::Set(Texture &image, int x, int y)
{
	sprite.setTexture(image);
	rect = FloatRect(x, y, size, size);

	dx = 0.05;
	currentFrame = 0;
	life = true;
}

// Эта функция осуществляет синхронизацию со временем, 
// реализацию функции коллизии, а также реализует анимацию персонажа.
void Enemy::Update(float time, float offsetX, float offsetY)
{
	rect.left += dx * time;

	Collision();


	currentFrame += time * period;
	if (currentFrame > 2) 
		currentFrame -= 2;

	// Определяет анимацию противника.
	sprite.setTextureRect(IntRect(18 * int(currentFrame), 0, size, size));
	// Определяет анимацию противника после победы героя над ним.
	if (!life) sprite.setTextureRect(IntRect(58, 0, size, size));

	// Установка спрайта противника по заданным координатам.
	sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

}

// Функция проверки столкновения противника с трубами 
// и нахождения на земле.
void Enemy::Collision() 
{
	// Цил проходящий по объектам карты
	for (int i = rect.top / size; i < (rect.top + rect.height) / size; i++)
		for (int j = rect.left / size; j < (rect.left + rect.width) / size; j++)
			// Условие нахождения объекта на карте с соответствующими ключами
			if ((TileMap[i][j] == 'P') || (TileMap[i][j] == '0'))
			{
				if (dx > 0) // Условие движения противника вправо.
				{
					// Определение точки столкновения
					rect.left = j * size - rect.width;
					// Осуществляет блуждание персонажа вперед и назад, 
					// отталкивающегося от объектов.
					dx *= -1; 
				}
				else if (dx < 0) // Условие движения персонажа влевл.
				{
					rect.left = j * size + size;  
					dx *= -1;
				}
			}
}