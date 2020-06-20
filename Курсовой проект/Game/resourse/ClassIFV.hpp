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
		if((Keyboard::isKeyPressed(Keyboard::LAlt) && isMoveATG[i] == false) && isAutoReloading == false)
		{
			vie[i] = dir;
			shell[i]->sprite.setPosition(x + 20, y + 20);
			isMoveATG[i] = true;
			isAutoReloading = true;
			AutoReloading = 0;
			FullReload[1] = 300;
			i++;
		}

		if(isAutoReloading == true && AutoReloading < FullReload[1])
		{
			AutoReloading += time;
		}
		else
		{
			if(i == shell.size())
			{
				FullReload[1] = 3000;
				i = 0;
			}
			else 
			isAutoReloading = false;
		}
		cout << i << endl;

		for(long unsigned int i = 0; i < shell.size(); i++)
		{
			if(TileMap[(int)shell[i]->sprite.getPosition().y / 32][(int)shell[i]->sprite.getPosition().x / 32] == '0')
			{
			isMoveATG[i] = false;
			shell[i]->sprite.setPosition(-15, -15);
			}

			if(isMoveATG[i] == true)
			{
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
		if(((Keyboard::isKeyPressed(Keyboard::Space) || isEntity == true) && isMove == false) && isReloading == false)
		{
			vie1 = dir;
			isMove = true;
			shell->sprite.setPosition(x + 20, y + 20);
			isReloading = true;
			reloading = 0;
		}
		if(TileMap[(int)shell->sprite.getPosition().y / 32][(int)shell->sprite.getPosition().x / 32] == '0')
		{
			isMove = false;
			shell->sprite.setPosition(-15, -15);
		}

		if(isReloading == true && reloading < FullReload[0])
		{
			reloading += time;
		}
		else
			isReloading = false;

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
		damage = 1.0;
		HitPoint = 3.0;
		AutoDamage = 0.5;
		isMoveATG.push_back(false);
	}
	//Метод стрельбы
	//Принимает снаряд, время и вектор очереди
	void fire(obj* shell, float time, vector<obj*> AutoGun)
	{
	 	gun(shell, time);

	 	if(AutoGun.size() > isMoveATG.size())
	 	{
	 		for(long unsigned int i = AutoGun.size() - isMoveATG.size(); i < AutoGun.size(); i++)
	 		{
	 			isMoveATG.push_back(false);
	 			vie.push_back(0);
	 		}
	 	}

	 	ATG(AutoGun, time);
	}
};