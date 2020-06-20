#include "player.h"
#include "map.h"

PLAYER::PLAYER(Texture &image) // Конструктор класса PLAYER отвечающий за получение и определение картинки в спрайт, а также создание рамки и определения смещения
{
	sprite.setTexture(image); //Определяем передаваемую ранее текстуру в спрайт.
	rect = FloatRect(100, 180, 16, 16); //Задаем прямоугольник, x, y координаты верхней левой координаты прямоугольника, остальные это ширина и высота

	dx = dy = 0.1; 
	currentFrame = 0;
}

void PLAYER::update(float time, float offsetX, float offsetY) // Эта функция осуществляет синхронизацию со временем, реализацию функции коллизии, а также реализует анимацию персонажа.
   {	
	  
	 rect.left += dx * time;	
     Collision(0);
   

	 if (!onGround) 
		 dy += 0.0005 * time;	

	 rect.top += dy * time;
	 onGround = false;
     Collision(1);
	

     currentFrame += time * 0.005; //Привязка кадра по времени к программе
     if (currentFrame > 3) currentFrame -= 3; //Условие смены кадров (картинок всего 3, меняется положение ног)


    if (dx > 0) 
		sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame), 144, 16, 16)); //Осуществление смены кадров при движении персонажа вперед
	if (dx < 0) 
		sprite.setTextureRect(IntRect(112 + 31 * int(currentFrame) +16, 144, -16, 16));//Осуществление смены кадров при движении персонажа назад (определено инвертацией от движения вперед)
  

	 sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
	 
	 dx = 0;
   }

void PLAYER::Collision(int num) //Функция осуществляет проверку столкновения персонажа с различными объекитами на карте, которые должны быть непроходиыми для персонажа.
{


	for (int i = rect.top / 16; i < (rect.top + rect.height) / 16; i++)
		for (int j = rect.left / 16; j < (rect.left + rect.width) / 16; j++)
		{
			if ((TileMap[i][j] == 'P') || (TileMap[i][j] == 'k') || (TileMap[i][j] == '0') || (TileMap[i][j] == 'r') || (TileMap[i][j] == 't') || (TileMap[i][j] == 'c')) //Условие нахождения различных объектов на карте.
			{
				if (dy > 0 && num == 1)  //Определение верхней координаты прямоугольника, при условии нахождения персонажа в воздухе и движения вниз.
				{
					rect.top = i * 16 - rect.height;  
					dy = 0;   
					onGround = true;
				}
				if (dy < 0 && num == 1) //Определение верхней координаты прямоугольника, при условии нахождения персонажа в воздухе и движения вверх.
				{
					rect.top = i * 16 + 16;   
					dy = 0;
				}
				if (dx > 0 && num == 0) //Определение левой координаты прямоугольника, при условии движения персонажа вперед и по земле.
				{
					rect.left = j * 16 - rect.width; 
				}
				if (dx < 0 && num == 0) //Определение левой координаты прямоугольника, при условии движения персонажа назад и по земле.
				{
					rect.left = j * 16 + 16; 
				}
			}
		}

}