#pragma once 

#include "ClassTanks.hpp"

//Класс Боевой Машины Пехоты (IFV)
//Методы стрельбы: Автопушки и неуправляемого снаряда полностью аналогичны описанным в MBT и в BMPT
class IFV : public Tanks
{
private:
	long unsigned int i = 0; 
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


	//Метод стрельбы
	//Выпускается один снаряд без возможноти управления
	//Принимает объект снаряда и время
	void gun(obj* shell, float time)
	{
		//Если нажат пробел и если не противниик, и если снаряд не в движении, и если не перезарядка
		if(((Keyboard::isKeyPressed(Keyboard::Space) || isEntity == true) && isMove == false) && isReloading == false)
		{
			vie1 = dir;	//снаярд принимает направления танчика
			isMove = true;	//Снаряд считается теперь в движение
			shell->sprite.setPosition(x + 20, y + 20);	//Перемещается на место вылета из танка
			isReloading = true;	//начало перезарядки
			reloading = 0;	//Обнуление времени перезарядки
		}

		//Проверка на столкновение со стеной 
		if(TileMap[(int)shell->sprite.getPosition().y / 32][(int)shell->sprite.getPosition().x / 32] == '0')
		{
			//если столкнулся, то остананавливается и перемещается за карту
			isMove = false;
			shell->sprite.setPosition(-15, -15);
		}
		//Перезарядка
		if(isReloading == true && reloading < FullReload[0])
		{
			reloading += time;
		}
		else
			isReloading = false;

		//Движени снаряда соотвесутвующее направлению танчика
		if(isMove == true)
		{
			switch(vie1)
			{ 
	 			case 1:  shell->sprite.move(-0.5 * time, 0); shell->sprite.setRotation(270); break;
				case 0:  shell->sprite.move(0.5 * time, 0); shell->sprite.setRotation(90); break;
				case 3:  shell->sprite.move(0, -0.5 * time); shell->sprite.setRotation(0); break;
				case 2:  shell->sprite.move(0, 0.5 * time); shell->sprite.setRotation(180); break;
			};
		}
	}
public:
	bool isMove = false;	//Переменная для проверки движения снаряда
	vector<bool> isMoveATG; //Вектор проверки движения для каждого 30-мм снаряда
	vector<int> vie; //Вектор направления для каждого снаряда
	int stv = 0;
	int vie1;
	float FullReload[2] = {1500, 0}; //Массив для полной перезарядки выстрела и касеты
	IFV(string F, float dX, float dY, float W, float H, float X, float Y) : Tanks(F, dX, dY, W, H, X, Y)
	{
		damage = 1.0;	//Установка урона для PTUR данного "танчика"
		AutoDamage = 0.5;	//Установка урона для автопушки данного "танчика"
	}
	//Метод стрельбы
	//Принимает снаряд, время и вектор очереди
	void fire(obj* shell, float time, vector<obj*> AutoGun)
	{
		//Вызов метода стрельбы
	 	gun(shell, time);

	 		for(long unsigned int i = 0; i < AutoGun.size(); i++)
	 		{
	 			isMoveATG.push_back(false);	//Добавдение в вектор состояния движения снарядов автопушки
	 			vie.push_back(0);			//Добавдение в вектор стандартного направления танчика
	 		}
	
	 	//вызов метода АвтоПушки
	 	ATG(AutoGun, time);
	}
};