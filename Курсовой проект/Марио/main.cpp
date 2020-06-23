// Подключаем часть библиотеки SFML с графикой
#include <SFML/Graphics.hpp>
// Подключаем часть библиотеки SFML с музыкой
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include "map.h"
#include "player.h"
#include "enemy.h"

using namespace sf;

//Переменные смещение по осям X и Y.
float offsetX = 0, offsetY = 0;


int main()
{ 
	int countJump = 0;
	// Создаем окно 400х250 с названием.
    RenderWindow window(VideoMode(400, 250), "Mario game");

	Font font; // Шрифт
	// Передаем нашему шрифту файл шрифта
	font.loadFromFile("CyrilicOld.ttf");
	// Создаем объект текст. закидываем в объект 
	// текст строку, шрифт, размер шрифта(в пикселях),
	// сам объект текст (не строка)
	Text text("", font, 15);
	// Покрасили текст в красный
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold); // Жирный текст.

	//Передача картинки с фигурками в текстуру
	Texture tileSet; 
	tileSet.loadFromFile("Mario_Tileset.png");

	
	Player Mario(tileSet);
	Enemy enemy;
	enemy.Set(tileSet,48 * 16, 13 * 16);


	Sprite tile(tileSet);

	SoundBuffer buffer; //Создание переменной класса "Буфер Звука"
	//Создание буфера и загрузка музыки в него из файла
	buffer.loadFromFile("Jump.ogg");
	//Загрузка буфера в переменную класса "Звук"
	Sound sound(buffer);

	// Создание текстур для меню
	Texture menu_texture1, menu_texture2;
	Texture menu_texture3, about_texture;
	menu_texture1.loadFromFile("111.png"); // Загрузка картинок в текстуры
	menu_texture2.loadFromFile("222.png");
	menu_texture3.loadFromFile("333.png");
	about_texture.loadFromFile("about.png");
	// Загрузка текстур в спрайты
	Sprite menu1(menu_texture1), menu2(menu_texture2);
	Sprite menu3(menu_texture3), about(about_texture);
	// Переменная на которой основана работа и закрытие меню
	bool Menu = 1;
	int MenuNum = 0; // Номер картинки
	// Установка картинки на позицию в окне по координатам
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 150);


	// меню
	while (Menu) //Пока значение Menu = 1(True)
	{
		//Устанавливаем цвет для картинки (Белый)
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		MenuNum = 0;
		window.clear(Color(0, 0, 0)); // Очистка окна

		//При наведение курсора мышки на поле в рамках указанных координат
		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
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

		// При нажатии левой кнопой мыши по полю пункта
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			// Если указан первый пункт "Новая игра", 
			// меню прекращает работу и запускается игра 
			if (MenuNum == 1)
				Menu = false; 
			// При выборе второго пункта меню "О программе".
			if (MenuNum == 2)
			{ 
				// Заготавливается картинка с описанием 
				window.draw(about);
				window.display(); // Выводится на экран
				// Картинка с описанием не закроестя пока 
				// не будет нажата кнопка "Escape". 
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}

			//Выбор пункта 3 "Выход" приводит к выходу из программы. 
			if (MenuNum == 3)
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

    Music music; // Создание переменной класса музыки.
	// Загружаем в переменную музыку из файла
    music.openFromFile("Mario_Theme.ogg");
    music.play(); // Вызов проигрывания музыки

	// Переменная для работы с временем
	Clock clock;

	// Основной цикл программы осуществляющий 
	// работу со временем и закрытием окна
    while (window.isOpen())
    { 
		// Задаем прошедшее время в микросекундах
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart(); // Перезапускаем время

		time = time / 500; // здесь регулируем скорость игры


        Event event;
		// Обработка события закрытия окна.
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)      
                window.close();
		}

		// Устовие когда при нажатии клавищи "Влево" 
		// происходит смещение по оси x на -0.1.
		if (Keyboard::isKeyPressed(Keyboard::Left))
			Mario.dx=-0.1; 

		// При нажатии клавищи "Вправо" происходит 
		// смещение по оси x на 0.1.   
	    if (Keyboard::isKeyPressed(Keyboard::Right))
			Mario.dx=0.1;

		// При нажатии клавищи "Вверх" происходит переход к условию
	    if (Keyboard::isKeyPressed(Keyboard::Up))
			if (Mario.onGround) // Если марио на земле
			{ 
				// Происходит перемещение персонажа 
				// вверх по координате Y
				Mario.dy = -0.27;
				Mario.onGround = false; 
				// Включается проигрывание ранее 
				// заготовленного звука прыжка
				sound.play();
				// Увеличивается счетчик прыжков
				countJump += 1;
			}
	 

		// Вызов функции обновления с параметрами, класса PLAYER.
		 Mario.Update(time, offsetX, offsetY);
		 enemy.Update(time, offsetX, offsetY);

		 // Условие пересечения прямоугольника модельки 
		 // "Марио" с прямоугольником модельки "Противника"
		 if  (Mario.rect.intersects(enemy.rect))
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
					// Если игрок сталкивается с врагом, а не подает 
					// на него, то он окрашивается в красны цвет
					Mario.sprite.setColor(Color::Red);
				}			 
			 }
		 }

		 // Если левая коордитата прямоугольника > 200
		 if (Mario.rect.left > 200)
			 offsetX = Mario.rect.left - 200; // Смещение



		 // Очищаем окно голубым цветом (Фон)
		 window.clear(Color(107, 140, 255));

		 // Цикл прохождения массива карты по ширине и высоте
		 for (int i=0; i < H; i++)
			 for (int j=0; j < W; j++)
			  { 
				 // Если в массиве встречен символ P, то по заданым 
				 // координатам с картинки, формируется моделька текстуры 
				if (TileMap[i][j] == 'P')  
					tile.setTextureRect(IntRect(143-16 * 3, 112, 16, 16));

				if (TileMap[i][j] == 'k')  
					tile.setTextureRect(IntRect(143, 112, 16, 16));
				                                 
   			    if (TileMap[i][j] == 'c')  
					tile.setTextureRect(IntRect(143 - 16, 112, 16, 16));

				if (TileMap[i][j] == 't')  
					tile.setTextureRect(IntRect(0, 47, 32, 95 - 47));

				if (TileMap[i][j] == 'g')  
					tile.setTextureRect(IntRect(0, 16 * 9 - 5, 3 * 16, 16 * 2 + 5));

				if (TileMap[i][j] == 'G')  
					tile.setTextureRect(IntRect(145, 222, 222 - 145 , 255 - 222));

			    if (TileMap[i][j] == 'd')  
					tile.setTextureRect(IntRect(0, 106, 74, 127 - 106));

				if (TileMap[i][j] == 'w')  
					tile.setTextureRect(IntRect(99, 224, 140 - 99, 255 - 224));

				if (TileMap[i][j] == 'r')  
					tile.setTextureRect(IntRect(143-32, 112, 16, 16));

				if ((TileMap[i][j] == ' ') || (TileMap[i][j] == '0')) 
					continue;

				// Текстура устонавливается на тоже место, что и 
				// соответствующий символ массива, по заданным размерам.
  			    tile.setPosition(j * 16 - offsetX, i * 16 - offsetY) ;
		        window.draw(tile);
		     }
		
		std::ostringstream playerScoreString; 
		// Занесли в переменную число очков, то есть формируем строку
		playerScoreString << countJump;
		// Задаем строку тексту и вызываем 
		// сформированную выше строку
		text.setString("Прыжки:" + playerScoreString.str());
		// Задаем позицию текста, отступая от центра камеры
		text.setPosition(0, 0);
		window.draw(text); // рисую этот текст

		window.draw(Mario.sprite); //Рисуем персонажа "Марио"
	    window.draw(enemy.sprite); //Рисуем персонажа "Противник"

		window.display(); // Вывод на дисплей
    }

    return 0;
}



