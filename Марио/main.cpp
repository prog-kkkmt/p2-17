#include <SFML/Graphics.hpp> //Подключаем часть библиотеки SFML с графикой
#include <SFML/Audio.hpp> //Подключаем часть библиотеки SFML с музыкой
#include <iostream>
#include <sstream>
#include "map.h"
#include "player.h"
#include "enemy.h"

using namespace sf;

float offsetX = 0, offsetY = 0; //Переменные смещение по осям X и Y.


int main()
{ 
	int countJump = 0;
    RenderWindow window(VideoMode(400, 250), "Mario game"); //создаем окно 400х250 с названием.

	Font font; //шрифт 
	font.loadFromFile("CyrilicOld.ttf"); //передаем нашему шрифту файл шрифта
	Text text("", font, 20); //создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setFillColor(Color::Red); //покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(Text::Bold); //жирный текст.

	Texture tileSet;
	tileSet.loadFromFile("Mario_Tileset.png");

	
	PLAYER Mario(tileSet);
	ENEMY enemy;
	enemy.set(tileSet,48*16,13*16);


	Sprite tile(tileSet);

	SoundBuffer buffer; //Создание переменной класса "Звук"
	buffer.loadFromFile("Jump.ogg"); //Создание буфера и загрузка музыки в него из файла
	Sound sound(buffer); //Загрузка буфера в переменную класса "Звук"

	Texture menu_texture1, menu_texture2, menu_texture3, about_texture; //Создание текстур
	menu_texture1.loadFromFile("111.png"); //Загрузка картинок в текстуры
	menu_texture2.loadFromFile("222.png");
	menu_texture3.loadFromFile("333.png");
	about_texture.loadFromFile("about.png");
	Sprite menu1(menu_texture1), menu2(menu_texture2), menu3(menu_texture3), about(about_texture); // Загрузка текстур в спрайты
	bool Menu = 1; //Лагический тип данных на котором основана работа и закрытие меню
	int MenuNum = 0; //Номер картинки
	menu1.setPosition(100, 30); // Установка картинки на позицию в окне по координатам
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);


	//меню
	while (Menu) //Пока значение Menu = 1(True)
	{
		menu1.setColor(Color::White); //Устанавливаем цвет для картинки (Белый)
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		MenuNum = 0;
		window.clear(Color(0, 0, 0)); // Очистка окна

		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) //При наведение курсора мышки на поле в рамках указанных координат
		{ 
			menu1.setColor(Color::Yellow); //Пункт меню окрашивается в желтый
			MenuNum = 1; //Указываем номер пункта меню
		}
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) 
		{ 
			menu2.setColor(Color::Yellow); 
			MenuNum = 2; 
		}
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) 
		{ 
			menu3.setColor(Color::Yellow);
			MenuNum = 3; 
		}

		if (Mouse::isButtonPressed(Mouse::Left)) // При нажатии левой кнопой мыши по полю пункта
		{
			if (MenuNum == 1) //Если указан первый пункт "Новая игра", меню прекращает работу и запускается игра 
				Menu = false; 
			if (MenuNum == 2) //При выборе второго пункта меню "О программе".
			{ 
				window.draw(about); //Заготавливается картинка с описанием 
				window.display(); //Выводится на экран
				while (!Keyboard::isKeyPressed(Keyboard::Escape)); //Картинка с описанием не закроестя пока не будет нажата кнопка "Escape". 
			}
			if (MenuNum == 3) //Выбор пункта 3 "Выход" приводит к выходу из программы. 
			{ 
				window.close(); 
				Menu = false;
			}

		}

		//Рисуем 3 надписи.
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display(); //Вывод на дисплей
	}

    Music music; //Создание переменной класса музыки.
    music.openFromFile("Mario_Theme.ogg"); //Загружаем в переменную музыку из файла
    music.play(); //Вызов проигрывания музыки

	Clock clock; //Определяем переменную класса время, для работы с милисекундами

    while (window.isOpen()) //Основной цикл программы осуществляющий работу со временем и закрытием окна
    { 
		
		float time = clock.getElapsedTime().asMicroseconds(); //Задаем прошедшее время в микросекундах
		clock.restart(); //Перезапускаем время

		time = time / 500;  // здесь регулируем скорость игры


        Event event;
        while (window.pollEvent(event)) //Обработка события закрытия окна.
        {
            if (event.type == Event::Closed)      
                window.close();
		}


		if (Keyboard::isKeyPressed(Keyboard::Left)) // Устовие когда при нажатии клавищи "Влево" происходит смещение по оси x на -0.1.
			Mario.dx=-0.1; 
       
	    if (Keyboard::isKeyPressed(Keyboard::Right)) //При нажатии клавищи "Вправо" происходит смещение по оси x на 0.1.   
			Mario.dx=0.1;
    
	    if (Keyboard::isKeyPressed(Keyboard::Up))	//При нажатии клавищи "Вверх" происходит переход к условию
			if (Mario.onGround) //Если марио на земле
			{ 
				Mario.dy = -0.27; //Происходит перемещение персонажа вверх по координате Y
				Mario.onGround = false;  
				sound.play(); //Включается проигрывание ранее заготовленного звука прыжка
				countJump += 1; //Увеличивается счетчик прыжков
			}
	 


		 Mario.update(time, offsetX, offsetY); //Вызов функции с параметрами, класса PLAYER.
		 enemy.update(time, offsetX, offsetY);


		 if  (Mario.rect.intersects(enemy.rect)) //Условие пересечения прямоугольника модельки "Марио" с прямоугольником модельки "Противника"
		 {
			 if (enemy.life) //Если противник жив
			 {
				if (Mario.dy > 0) //И персонаж игрока приземлился, тогда
				{
					enemy.dx = 0; //Прекращается перемещение противника
					Mario.dy = -0.2; //Персонаж игрока подпрыгивает
					enemy.life = false;
				}
				else
				{
					Mario.sprite.setColor(Color::Red); //Если игрок сталкивается с врагом, а не подает на него, то он окрашивается в красны цвет
				}			 
			 }
		 }


		 if (Mario.rect.left > 200) //Усли левая коордитата прямоугольника > 200
			 offsetX = Mario.rect.left - 200;  //смещение




		 window.clear(Color(107, 140, 255)); //Очищаем окно голубым цветом(Фон)

		 for (int i=0; i < H; i++) //Цикл прохождения массива карты по ширине и высоте
			 for (int j=0; j < W; j++)
			  { 
				if (TileMap[i][j] == 'P')  tile.setTextureRect(IntRect(143-16 * 3, 112, 16, 16)); //Если в массиве встречен символ P, то по заданым координатам с картинки, формируется моделька текстуры 

				if (TileMap[i][j] == 'k')  tile.setTextureRect(IntRect(143, 112, 16, 16));
				                                 
   			    if (TileMap[i][j] == 'c')  tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));

				if (TileMap[i][j] == 't')  tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));

				if (TileMap[i][j] == 'g')  tile.setTextureRect(IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

				if (TileMap[i][j] == 'G')  tile.setTextureRect(IntRect(145, 222, 222 - 145 , 255 - 222));

			    if (TileMap[i][j] == 'd')  tile.setTextureRect(IntRect(0, 106, 74, 127 - 106));

				if (TileMap[i][j] == 'w')  tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));

				if (TileMap[i][j] == 'r')  tile.setTextureRect(IntRect(143-32, 112, 16, 16));

				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) continue;

  			    tile.setPosition(j * 16 - offsetX, i * 16 - offsetY) ; //Текстура устонавливается на тоже место, что и соответствующий символ массива, по заданным размерам.
		        window.draw(tile);
		     }
		 
		std::ostringstream playerScoreString;    // объявили переменную
		playerScoreString << countJump;		//занесли в нее число очков, то есть формируем строку
		text.setString("Сделано прыжков:" + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(0, 0);//задаем позицию текста, отступая от центра камеры
		window.draw(text);//рисую этот текст

		window.draw(Mario.sprite); //Рисуем персонажа "Марио".
	    window.draw(enemy.sprite); //Рисуем персонажа "Противник"

		window.display(); //Вывод на дисплей.
    }

    return 0;
}



