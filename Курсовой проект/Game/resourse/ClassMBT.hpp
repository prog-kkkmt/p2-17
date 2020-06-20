#pragma once 

#include "ClassTanks.hpp"

//Класс Основого Боевого Танка(Main Battle Tank)
class MBT : public Tanks
{
private:
	//Метод стрельбы
	//Выпускается один снаряд без возможноти управления
	//Принимает объект снаряда и время
	void gun(obj* shell, float time)
	{
		 //Если нажат пробел и если не противниик, и если снаряд не в движении, и если не перезарядка
		if(((Keyboard::isKeyPressed(Keyboard::Space) || isEntity == true) && isMove == false) && isReloading == false)
		{
			vie = dir; //снаярд принимает направления танчика
			isMove = true; //Снаряд считается теперь в дивжения
			shell->sprite.setPosition(x + 20, y + 20); //Перемещается на место вылета из танка
			//начало перезарядка
			isReloading = true; 
			reloading = 0;
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
			switch(vie)
			{ 
	 			case 1:  shell->sprite.move(-0.5 * time, 0); shell->sprite.setRotation(270); break;
				case 0:  shell->sprite.move(0.5 * time, 0); shell->sprite.setRotation(90); break;
				case 3:  shell->sprite.move(0, -0.5 * time); shell->sprite.setRotation(0); break;
				case 2:  shell->sprite.move(0, 0.5 * time); shell->sprite.setRotation(180); break;
			};
		}
	}

public:
	bool isMove = false; //Переменная проверки движения снаряда
	int vie;			 //Переменная направления для снаряда
	MBT(string F, float dX, float dY, float W, float H, float X, float Y) : Tanks(F, dX, dY, W, H, X, Y)
	{
		damage = 1.0; //Установка урона
		FullReload[0] = 1500;	//Установка времени перезарядки
	}

	//Метод стрельбы
	//Принимает снаряд, время и вектор очереди
	void fire(obj* shell, float time, vector<obj*> AutoGun)
	{
		gun(shell, time);
	}
};