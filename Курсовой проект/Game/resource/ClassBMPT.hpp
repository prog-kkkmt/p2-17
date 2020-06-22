#pragma once 

#include "ClassTanks.hpp"

class BMPT : public Tanks
{
private:
	long unsigned int i = 0;	//Счетчик автоматического огня
	//Метод Противотанковой Управляемой Ракеты(ПТУР)
	//Принимает ПТУР и время
	//Всего 4 ракеты, которые вылетают поочереди и могут управляться игроком
	//Аналогичен неуправляемой стрельбе
	void ATR(obj* shell, float time)
	{
		if(((Keyboard::isKeyPressed(Keyboard::Space) || isEntity == true) && isMove == false) && isReloading == false)
		{
			//ПТУР вылетает из двух напрвлящих поочереди
			//После 4 залпа начинается перезарядка всех 4-х ракет
			//Между пусками есть перезарядка
			if(stv % 2 == 0)
				shell->sprite.setPosition(x + 30, y + 30);	//Установка позиции на одну из направляющих
			else if(stv % 2 == 1)
				shell->sprite.setPosition(x + 10, y + 10);	//Установка позиции на другую направляющую

			//Начало большой перезарядки после отстрела 4 ракеты
			if(stv == 3)
			{
				stv = 0;
				FullReload[0] = 6000;
			}
			//Иначе увелечение числа выпущенных ракет
			else
				stv++;

			isReloading = true; //Запуск перезарядки
			reloading = 0;		//Обнуление значения перезарядки
			isMove = true;		//Ракета начинается считаться в движении
		}
		//ПТУР привязан на всем протижении полета к направлению танка.
		// При смене направления танка менятся направление полета ПТУРа
		switch(dir)
			{ 
	 			case 1:  shell->sprite.move(-0.3 * time, 0); shell->sprite.setRotation(270); break;
				case 0:  shell->sprite.move(0.3 * time, 0); shell->sprite.setRotation(90); break;
				case 3:  shell->sprite.move(0, -0.3 * time); shell->sprite.setRotation(0); break;
				case 2:  shell->sprite.move(0, 0.3 * time); shell->sprite.setRotation(180); break;
			};
		//Проверка столкновения с картой
		if(TileMap[(int)shell->sprite.getPosition().y / 32][(int)shell->sprite.getPosition().x / 32] == '0')
		{
			//Движение прекращается
			//И снаряд "исчезает". Переносится за облость видимости игрока
			isMove = false;
			shell->sprite.setPosition(-15, -15);
		}

		//Перезарялка внутри залпп
		if(isReloading == true && reloading < FullReload[0])
			reloading += time;
		else
		{
			isReloading = false;	
			FullReload[0] = 2000; //время между запуском ракет внутри залпа
		}
	}
	//Метод Автоматической Стрельбы
	//В касете находится 5 снарядов с небольшой перезарядкой между залпами.
	// После отсртрела 5 снарядов начинается долгая перезарядка всей касеты
	// Принимает вектор снарядом и время
	// Алгоритм аналогичен стрельбое неуправляемым снарядом, только для 5-ти элементов
	void ATG(vector<obj*> shell, float time)
	{
		//Если нажат пробел и снаряд[i] не находится в движении, и не на перезарядке
		if((Keyboard::isKeyPressed(Keyboard::LAlt) && isMoveATG[i] == false) && isAutoReloading == false)
		{
			vie[i] = dir;									//снаряд принимает направления танчика
			shell[i]->sprite.setPosition(x + 20, y + 20);	//Перемещается на место вылета из танка
			isMoveATG[i] = true;							//Снаряд считается теперь в движение
			isAutoReloading = true;							//Запуск малой перезарядки (между снарядами)						
			AutoReloading = 0;								//Обнуление переменной перезарядки
			FullReload[1] = 300;							//Задание времени малой перезарядки
			i++;											//переход к следующему сняряду
		}

		//пока "Перезарядка" идет и меньше времени перезарядки
		//идёт Перезарядка.

		if(isAutoReloading == true && AutoReloading < FullReload[1])
		{
			AutoReloading += time;
		}
		//Иначе проверяется условия
		else
		{
		//Если снаряд последний в очереди. т.е равен последнему элементу,
		//То начинает перезаряжается вся касета(большая перезарядка) и следующий готовый к стрельбе становится снарядом[0]
			if(i == shell.size())
			{
				FullReload[1] = 3000;
				i = 0;
			}
			//Иначе перезарядка окончена 
			else 
			isAutoReloading = false;
		}
		//Цикл просчета движения и столкновения каждого снаряда
		for(long unsigned int i = 0; i < shell.size(); i++)
		{
			//Проверка столкновения с препядствием карты
			if(TileMap[(int)shell[i]->sprite.getPosition().y / 32][(int)shell[i]->sprite.getPosition().x / 32] == '0')
			{
			//Движение прекращается
			//И снаряд[i] "исчезает". Переносится за облость видимости игрока
			isMoveATG[i] = false;
			shell[i]->sprite.setPosition(-15, -15);
			}
			//Если снаряд[i] находится в движении
			if(isMoveATG[i] == true)
			{
				//Полет снаряда[i] в соответствии с заданным направлением[i]
				switch(vie[i])
				{ 
			 		case 1:  shell[i]->sprite.move(-0.5 * time, 0); shell[i]->sprite.setRotation(270); break;
					case 0:  shell[i]->sprite.move(0.5 * time, 0); shell[i]->sprite.setRotation(90); break;
					case 3:  shell[i]->sprite.move(0, -0.5 * time); shell[i]->sprite.setRotation(0); break;
					case 2:  shell[i]->sprite.move(0, 0.5 * time); shell[i]->sprite.setRotation(180); break;
				};
			}
		}
	}

public:
	bool isMove = false;
	vector<bool> isMoveATG; 		//Вектор проверки движения для каждого снаряда
	vector<int> vie;				//Вектор направления для каждого снаряда
	int stv = 0;					//Счетчик напрвления из которой вылетит ПТУР
	float FullReload[2] = {0, 0};	//Массив для полной перезарядки ПТУРов и касеты
	BMPT(string F, float dX, float dY, float W, float H, float X, float Y) : Tanks(F, dX, dY, W, H, X, Y)
	{
		damage = 2.0;			//Установка урона для PTUR данного "танчика"
		AutoDamage = 0.5;				//Установка урона для автопушки данного "танчика"
	}
	//Метод стрельбы
	//Заполняет вектора вида и проверки движения для АвтоПушки
	//Принимает снаряд, время и вектор очереди
	void fire(obj* shell, float time, vector<obj*> AutoGun)
	{
		//вызов метода ПТУР
	 	ATR(shell, time);

	 	//Заполнение векторов стандартными значениями

	 	if(AutoGun.size() > isMoveATG.size())
	 	{
	 		for(long unsigned int i = 0; i < AutoGun.size(); i++)
	 		{
	 			isMoveATG.push_back(false);	//Добавдение в вектор состояния движения снарядов автопушки
	 			vie.push_back(0);			//Добавдение в вектор стандартного направления танчика
	 		}
	 	}
	 	//вызов метода АвтоПушки
	 	ATG(AutoGun, time);
	}
};