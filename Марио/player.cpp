#include "player.h"
#include "map.h"

// Ширина, и высота используемой рамки
const int size = 16;
// Степень уменьшения скорости анимации
const double period = 0.005;

// Конструктор класса PLAYER отвечающий за получение 
// и определение картинки в спрайт, 
// а также создания рамки и определения смещения
PLAYER::PLAYER(Texture &image)
{
	// Определяем передаваемую ранее текстуру в спрайт.
	sprite.setTexture(image);
	// Задаем прямоугольник, x, y координаты верхней левой 
	// координаты прямоугольника, остальные это ширина и высота
	rect = FloatRect(100, 180, size,size);

	dx = dy = 0.1; 
	currentFrame = 0;
}

// Эта функция осуществляет синхронизацию со временем, 
// реализацию функции коллизии, а также анимации персонажа.
void PLAYER::update(float time, float offsetX, float offsetY)
   {	
	  
	 rect.left += dx * time;	
     Collision(0);
   

	 if (!onGround) 
		 dy += 0.0005 * time; // Скорость (высота) прыжка вверх

	 rect.top += dy * time;
	 onGround = false;
     Collision(1);
	

     currentFrame += time * period; //Привязка кадра по времени к программе
	 //Условие смены кадров (картинок всего 3, меняется положение ног)
     if (currentFrame > 3) currentFrame -= 3;


    if (dx > 0) 
		//Осуществление смены кадров при движении персонажа вперед
		sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame), 144, size, size));
	if (dx < 0)
		//Осуществление смены кадров при движении персонажа 
		//назад (определено инверсией от движения вперед)
		sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame) +size, 144, size * -1, size));
  
	 //Определение позиции появления персонажа
	 sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	 
	 dx = 0;
   }

// Функция осуществляет проверку столкновения персонажа 
// с различными объекитами на карте, играющими роль барьеров
void PLAYER::Collision(int num)
{


	for (int i = rect.top / size; i < (rect.top + rect.height) / size; i++)
		for (int j = rect.left / size; j < (rect.left + rect.width) / size; j++)
		{
			//Условие нахождения различных объектов на карте.
			if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') || (TileMap[i][j] == 't') || (TileMap[i][j] == 'c'))
			{
				// Определение верхней координаты прямоугольника, при 
				// условии нахождения персонажа в воздухе и движения вниз.
				if (dy > 0 && num == 1) 
				{
					rect.top = i * size - rect.height;  
					dy = 0;   
					onGround = true;
				}
				// Определение верхней координаты прямоугольника, при 
				// условии нахождения персонажа в воздухе и движения вверх.
				if (dy < 0 && num == 1) 
				{
					rect.top = i * size + size;   
					dy = 0;
				}
				// Определение левой координаты прямоугольника, при 
				// условии движения персонажа вперед и по земле.
				if (dx > 0 && num == 0)
				{
					rect.left = j * size - rect.width; 
				}
				// Определение левой координаты прямоугольника, при 
				// условии движения персонажа назад и по земле.
				if (dx < 0 && num == 0)
				{
					rect.left = j * size + size; 
				}
			}
		}

}