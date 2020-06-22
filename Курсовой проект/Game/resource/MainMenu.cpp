//Подключение файла класса кнопок
#include "ButtonClass.hpp"
//подключение файла игрвого процесса
#include "mainGame.hpp"

//Подсветка кнопок
//Приниается вектор всех кнопок и вектор координат курсора
void press(vector<Button*> v, Vector2f pos)
{
	//i = 1, кроме 1 элемента, это фон
	for(long unsigned int i = 1; i < v.size(); i++)
		{
			//Если мышка неведена на кнопку, то она подсвечивается черным 
			//(!= 5) кроме 5 элемента, это окно помощи
			if(v[i]->sprite.getGlobalBounds().contains(pos.x, pos.y) && i != 5)
				v[i]->sprite.setColor(Color::Black);
			else if (i != 5)
				v[i]->sprite.setColor(Color::White);
		}
}

//Смена кадров фона
//Принимется фон окна, время, номер кадра
void FrameMenu(Button* menu, float time, float &CurrentFrame)
{ 
	//служит для прохождения по "кадрам"
	CurrentFrame += 0.005 * time;
		if(CurrentFrame > 3) //Если кадр стал 3, то переходи назад к 0
			CurrentFrame = 0;
	menu->sprite.setTextureRect(IntRect(0 + (int(CurrentFrame) * 1280), 0, 1280, 720)); //Умножаем на координаты картинки получая нужный кадр
}

//Основная фунция главного меню
void launcher()
{
	RenderWindow window(VideoMode(1280, 720), "Launcher"); //создание окна 1280х720

	float CurrentFrame = 0; //Номер кадра
	bool isOpen = true; //открыто ли окно помощи

	Clock clock;
	
	vector<Button*> mass; //вектор кнопок
	mass.push_back(new Button("Main_menu.png", 0, 0, 1280, 720, 0, 0)); //Фон [0]
	mass.push_back(new Button("Buttons.png", 2, 2, 200, 50, 1000, 80)); //Новая игра [1]
	mass.push_back(new Button("Buttons.png", 2, 52, 200, 50, 1000, 130)); //Редактор [2]
	mass.push_back(new Button("Buttons.png", 2, 102, 200, 50, 1000, 180)); //Помощь [3]
	mass.push_back(new Button("Buttons.png", 2, 152, 200, 50, 1000, 230)); //Выход [4]
	mass.push_back(new Button("Buttons.png", 202, 2, 240, 280, 750, 80)); //Окно помощи[5]
	mass[5]->sprite.setColor(Color(0, 0, 0, 1)); //Покраска окна помощи в прозрачный

//===================================================// Ниже самое важное, малоизменяемое
	while(window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)

		srand(time(NULL));
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event close;
		while(window.pollEvent(close))
		{
			if(close.type == Event::Closed)
				window.close();
//==========================================// Тут выбор пункта меню
			else if(Mouse::isButtonPressed(Mouse::Left))
			{
				if(mass[1]->sprite.getGlobalBounds().contains(pos.x, pos.y)) //Если нажата "Новая игра" закрываем окно лайнчера и запускаем игру
				{
					window.close();
					game(); //Функция игры. Вызывается из "mainGame.hpp"
				}
				if(mass[3]->sprite.getGlobalBounds().contains(pos.x, pos.y)) //Если нажата "Помощь" то, окно помощи становится видимым
				{
					if(isOpen == false)
					{
						mass[5]->sprite.setColor(Color(0, 0, 0, 1)); //при повторном нажатии окно становится невидимым
						isOpen = true;
					}
					else
					{
						mass[5]->sprite.setColor(Color(255, 255, 255, 255));
						isOpen = false;
					}
				}
				if(mass[4]->sprite.getGlobalBounds().contains(pos.x, pos.y)) //При нажатии выход, лаунчер закрывется и ничего не происходи
				{
					window.close();
				}
			}
		}
//===================================================// Выше самое важное, малоизменяемое
		press(mass, pos);
		FrameMenu(mass[0], time, CurrentFrame);
//==================================================// Рисуем всё, что есть
	window.draw(mass[0]->sprite);

	for(long unsigned int i = 1; i < mass.size(); i++)
	{
		window.draw(mass[i]->sprite);
	}
		window.display();
	}
}