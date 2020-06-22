#pragma once 
//Подключение файла класса объектов
#include "ClassOBJ.hpp"
//Подключение файла карты и её класса
#include "map.hpp"

//Класс общих характеристик и методов танчиков
class Tanks
{
protected:
	string File; 						//Название файла текстуры
	Image image;						//Объект изображения
	Texture texture;					//Объект текстуры
	float speed = 0.0; 					//Скорость передвижения всех
	float x, y, dx, dy, w, h, fx, fy;	//координаты, начальная точки спрайта, конечные, временные для передивжения
	bool isEntity = false; 				//Переменная проверки на игрока или противника
	int dir = 0; 						//Переменная направления танчика
	float reloading = 0;				//Переменная перезарялки
	float FullReload[2] = {};			//Массив времени перезарядки
	float AutoReloading = 0;			//Переменная полного времени перезарядки АвтоПушки
public:
	float damage = 0.0;					//Переменная урона обычной пушкой или ПТУРОМ
	float AutoDamage = 0.0;				//Переменная урона снарядом автопушки
	float HitPoint = 3.0;				//Кол-во жизней
	bool isReloading = false; 			//Переменная проверки статуса перезарядка
	bool isAutoReloading = false; 		//Переменная проверки статуса перезарядки автопушки
	bool isDead = false; 				//Переменная проверки статуса жизни
	int Score = 0;						//Переменная очков

	Sprite sprite;						//Объект спрайта

//Конструктор танчика, задается спрайт и точка появления
	Tanks(string F, float dX, float dY, float W, float H, float X, float Y)
	{
		File = F;
		w = W; h = H;	
		x = X; y = Y;
		dx = dX; dy = dY;
		image.loadFromFile("images/" + File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(dx, dy, w, h));
		sprite.setPosition(x, y);
	}

//Метод управления
//Принимает время
	void control(float time)
	{
			if(Keyboard::isKeyPressed(Keyboard::Up)) //Если нажата стрелочка вверх указывается направление и скорость
			{
				dir = 3; speed = 0.2;
				sprite.setTextureRect(IntRect(dx, dy, 40, 40)); //Перерисовывается танк в соответствии с направлением движения
			}
			if(Keyboard::isKeyPressed(Keyboard::Down)) //Вниз, аналогично вверх
			{
				dir = 2; speed = 0.2;
				sprite.setTextureRect(IntRect(dx + 40, dy + 40, -40, -40));
			}
			if(Keyboard::isKeyPressed(Keyboard::Left)) //Влево, аналогично вверх
			{

				dir = 1; speed = 0.2;
				sprite.setTextureRect(IntRect(dx + 40, dy + 40 + 41, -40, -40));
			}
			if(Keyboard::isKeyPressed(Keyboard::Right)) //Вправо, аналогично вверх
			{
				dir = 0; speed = 0.2;
				sprite.setTextureRect(IntRect(dx, dy + 41, 40, 40));
			}
	}

	//Метод передвижения
	//Принимаеися время
	void update(float time)
	{
		switch(dir)	//Движение танка исходя из направления танчика
		{
			case 0:  fx = speed; fy = 0; break;
			case 1:  fx = -speed; fy = 0; break;
			case 2:  fx = 0; fy = speed; break;
			case 3:  fx = 0; fy = -speed; break;
		}

		//для плавного движения пройденное растояние умножается на время
		x += fx * time;
		y += fy * time;

		speed = 0; //если ничего не нажато, то танк останавливается
		sprite.setPosition(x, y); //Задание позии танчику

	}
	//Метод проверки столкновения
	void interactionWithMap()
	{
		//Циклы прохода по карте
			//проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера 32*32
			//x делим на 32, тем самым получаем левый квадратик, с которым "Танчик" соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). 
			//А j<(x + w) / 32 - условие ограничения координат по x. то есть координата самого правого квадрата, который соприкасается с "Танчиком". 
			//таким образом идем в цикле слева направо по х, проходя по от левого квадрата (соприкасающегося с "Танчиком"), до правого квадрата (соприкасающегося с "Танчиком")
		for(int i = y / 32; i < (y + h) / 32; i++) 
		for(int j = x / 32; j < (x + w) / 32; j++) 	{
			if(TileMap[i][j] == '0') //Если объект ст
			{
				if (fy > 0)//если мы шли вниз,
							y = i * 32 - h;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
				if (fy < 0)
							y = i * 32 + 32;//аналогично с ходьбой вверх. fy<0, значит мы идем вверх (вспоминаем координаты паинта)
				if (fx > 0)
							x = j * 32 - w;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
				if (fx < 0)
							x = j * 32 + 32;//аналогично идем влево
			}
		}
	}

	//Метод противников
	//Принимается время
	void Artificial_Intelligence(float time)
	{
		isEntity = true;
		int randGus = 1 + rand() % 10; //Счётчик случайного выбора направления движения
		//Аналогично передвижению игрока
			if (randGus == 1 || randGus == 5) 
			{ 
				dir = 3; speed = 0.2;
				sprite.setTextureRect(IntRect(dx, dy, 40, 40));
			} 
			if (randGus == 12 || randGus == 6)
			{  	
				dir = 2; speed = 0.2;
				
				sprite.setTextureRect(IntRect(dx + 40, dy + 40, -40, -40));
			}
			if (randGus == 3 || randGus == 7)
			{  
				dir = 1; speed = 0.2;
				sprite.setTextureRect(IntRect(dx + 40, dy + 40 + 41, -40, -40));
			} 
			if (randGus == 4 || randGus == 8)
			{ 
				dir = 0; speed = 0.2;
				sprite.setTextureRect(IntRect(dx, dy + 41, 40, 40));
			}
	}

//Перегруженный метод засчитывания попадания
//Принимается объкт снаряда, переменные места возраждения, получаемый урон, вектор объектов автопушки, получаемый урон Автопушки,
//Объект попадания обычного снаряд и объект попадания снаряда автопушки 
//Толко для противников
	void dead(obj* Shell, float a, float b, float Fdamage, vector<obj*> AutoGun, float FdamageA, obj* fireAutoGun, obj* fireGun)
	{
		if(Shell->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) //Елси спрайт танчика и снаряда пересеклись засчитано попадание
		{
			fireGun->sprite.setPosition(Shell->sprite.getPosition().x, Shell->sprite.getPosition().y);//На месте попадания рисуется эффект попадния
			Shell->sprite.setPosition(-15, -15);	//Попавший снаряд "исчезает" за карту
			HitPoint -= Fdamage;					//Уменьшение жизней
			if(HitPoint <= 0)						//Если жизни стали меньше или равны 0 то статус уничтожения становится активным
			{
				isDead = true;
			}
		}
		for(long unsigned int i = 0; i < AutoGun.size(); i++)	//Аналогично со снарядом, только для АвтоПушки
		{	
			if(AutoGun[i]->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
			{
				fireAutoGun->sprite.setPosition(AutoGun[i]->sprite.getPosition().x, AutoGun[i]->sprite.getPosition().y);
				AutoGun[i]->sprite.setPosition(-15, -15);
				HitPoint -= FdamageA;
				if(HitPoint <= 0)
				{
					isDead = true;
					Score = 0;
				}
			}
		}
	}

//Перегруженный метод засчитывания попадания
//Принимается объкт снаряда, переменные места возраждения, получаемый урон, объект попадания обычного снаряда
//Аналогично первому методу
// только для игрока
	void dead(obj* Shell, float a, float b, float Fdamage, obj* fireGun)
	{
		if(Shell->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		{
			fireGun->sprite.setPosition(Shell->sprite.getPosition().x, Shell->sprite.getPosition().y);
			Shell->sprite.setPosition(-15, -15);
			HitPoint -= Fdamage;
			if(HitPoint <= 0)
			{
				HitPoint = 3;
				//Перенос игрока на место появления
				x = a; 
				y = b;
				Score = 0;
			}
		}
	}

//Виртульная фунция для стрельбы
	virtual void fire(obj* shell, float time, vector<obj*> AutoGun)
	{

	}
};
