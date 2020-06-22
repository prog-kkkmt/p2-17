//Подключение файлов классов "Танчиков"
#include "ClassMBT.hpp"
#include "ClassBMPT.hpp"
#include "ClassIFV.hpp"
#include "ClassOBJ.hpp"

//Подсветка кнопок
//Приниается вектор всех кнопок и вектор координат курсора
void press(vector<obj*> v, Vector2f pos)
{
	for(long unsigned int i = 0; i < v.size(); i++)
		{
			if(v[i]->sprite.getGlobalBounds().contains(pos.x, pos.y))
				v[i]->sprite.setColor(Color(0, 0, 0, 1));
			else
				v[i]->sprite.setColor(Color::White);
		}
}


//Отрисовка карты
//Принимается объект карты, граница по х, граница по у
void MapFunct(MapClass *MapObjF, int i , int j)
{
	if(TileMap[i][j] == '0') MapObjF->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	if(TileMap[i][j] == ' ') MapObjF->sprite.setTextureRect(IntRect(32, 0, 32, 32));
	MapObjF->sprite.setPosition(j * 32, i * 32);
}

//Выбор Танчика
//Принимается переменная выбора
void choice(int &i_choice_F)
{
	RenderWindow window(VideoMode(320, 136), "Choice Tanks"); //Рисуем отдельное окно
	Clock clock; //создание переменную времени, т.о. привязка ко времени(а не загруженности/мощности процессора). 

	//Создание вектора изображений при выборе "Танчика"
	vector<obj*> choicePlayer;
	//Заполнение вектора текстурами танчиков
	choicePlayer.push_back(new obj("itemsAll.png", 0, 187, 100, 136, 0, 0));
	choicePlayer.push_back(new obj("itemsAll.png", 100, 187, 100, 136, 110, 0));
	choicePlayer.push_back(new obj("itemsAll.png", 200, 187, 100, 136, 220, 0));

	while(window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
		Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)

		//Для плавности игры
		float time = clock.getElapsedTime().asMicroseconds(); // дать прошедшее время в микросекундах
		clock.restart(); //Перезагрузка времени
		time = time / 800; //скорость игры

		
		Event close;
		while(window.pollEvent(close))
		{
			if(close.type == Event::Closed)
				window.close();
			//Если нажата левая кнопка мыши
			else if(Mouse::isButtonPressed(Mouse::Left))
			{
			//И если позиция курсора наведена на одном из "танчиков" 
			//то выбор записывается и окно выбора закрывается
				if(choicePlayer[0]->sprite.getGlobalBounds().contains(pos.x, pos.y))
					{
						i_choice_F = 1;
						window.close();
					}
				if(choicePlayer[1]->sprite.getGlobalBounds().contains(pos.x, pos.y))
					{
						i_choice_F = 2;
						window.close();
					}
				if(choicePlayer[2]->sprite.getGlobalBounds().contains(pos.x, pos.y))
					{
						i_choice_F = 3;
						window.close();
					}
			}
		}
	press(choicePlayer, pos); //Вызываем фунцию подсветки

	//Рисуем все элемениы
	for(long unsigned int i = 0; i < choicePlayer.size(); i++)
		window.draw(choicePlayer[i]->sprite);

	window.display();
	}
}

//Фунция готовности к стрельбе
//Принимается переменная перезарядки
string isFire(bool isReloadingF)
{
	string s = "ok!";

	if(isReloadingF == true)
		s ="...";

	return s;
}

//Фунция записи очков, максимума очков, перезарядки
//Принимается объект текста, очки, максимальные очки, кол-во жизней, переменная перезарядки 1 и 2 вида оружия
void Score(Text *text, int ScoreF, int *MaxScoreF, float HitPointF, bool isReloadingF, bool isAutoReloadingF)
{
	ostringstream Scr;

	if(ScoreF > *MaxScoreF)
		*MaxScoreF = ScoreF;

	Scr << ScoreF << "\n\n" << *MaxScoreF << "\n\n" << HitPointF << "\n\n" << isFire(isReloadingF) << "\n\n" << isFire(isAutoReloadingF)<< "\n\n";
	text->setString(Scr.str());
	text->setPosition(1230, 735);
}


//Основная функция игры
void game()
{

//Объект текста для вывода данных на экран
	Font font;
	font.loadFromFile("resource/9303.ttf");
	Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::White);


	MapClass MapObj; //Объект карты

	Tanks *player; //указатель на объект игрока, инициализируем конструктором по умолчанию
	obj* playerShell; //указатель на объект снаряда игрока, инициализируем конструктором по умолчанию
	obj* playerInf = new obj("Buttons.png", 443, 2, 251, 280, 1026, 730); //Окно основной информации в нижнем правом углу
	vector<obj*> playerAutoShell; //Объект 30-мм снарядов игрока

	obj* fireAutoGun = new obj("itemsAll.png", 160, 20, 10, 10, 300, 300); //указатель на объект эффекта попадания от АвтоПушки
	obj* fireGun = new obj("itemsAll.png", 173, 21, 15, 15, 400, 400); //указатель на объект эффекта попадания от снаряда

	int i_choice; //Переменная выбора танчика
	int MaxScore = 0; //Переменная максималных очкнов
	int Respawn = 0; //Переменная спавна противника
	float TimeResp = 0; //Переменная времени спавна противника
	float TimeFire = 0; //Переменная времени стрельбы противником

	choice(i_choice); //Вызов фунции выбора

//===================================================//Создание танчика по выбору игрока
	if(i_choice == 1)
	{
		MBT* ptanks = new MBT("Tanks.png", 0, 82, 40, 40, 942, 942); 	//создание указателя на объект "танчика" типа MBT
		obj* pShell = new obj("itemsAll.png", 160, 0, 6, 15, -15, -15);	//создание указателя на объект выбранного для "танчика" снаряда
		player = ptanks;												//Присвоение указателя на созданный объект "тачника" на объект игрока
		playerShell = pShell;											//Присвоение указателя на созданный объект снаряда "танчика" на объект снаряда игрока
	}
	else if(i_choice == 2)
	{
		BMPT* ptanks = new BMPT("Tanks.png", 41, 82, 40, 40, 942, 942); //создание указателя на объект "танчика" типа BMPT
		obj* pShell = new obj("itemsAll.png", 167, 0, 6, 18, -15, -15);	//создание указателя на объект выбранного для "танчика" снаряда
		player = ptanks;												//Присвоение указателя на созданный объект "тачника" на объект игрока
		playerShell = pShell;											//Присвоение указателя на созданный объект снаряда "танчика" на объект снаряда игрока

		for(int i = 0; i < 5; i++)	//Заполнения вектора 30-мм снарядов так, как данный тип танчика имеет данное вооружение
			playerAutoShell.push_back(new obj("itemsAll.png", 172, 0, 4, 6, 300, 300));	
	}
	else if(i_choice == 3)
	{
		IFV* ptanks = new IFV("Tanks.png", 82, 82, 40, 40, 942, 942);	//создание указателя на объект "танчика" типа IFV
		obj* pShell = new obj("itemsAll.png", 160, 0, 6, 18, -15, -15);	//создание указателя на объект выбранного для "танчика" снаряда
		player = ptanks;												//Присвоение указателя на созданный объект "тачника" на объект игрока
		playerShell = pShell;											//Присвоение указателя на созданный объект снаряда "танчика" на объект снаряда игрока

		for(int i = 0; i < 5; i++)	//Заполнения вектора объектами 30-мм снарядов так, как данный тип танчика имеет данное вооружение
			playerAutoShell.push_back(new obj("itemsAll.png", 172, 0, 4, 6, 300, 300));
	}
	

	//MBT player("Tanks.png", 0, 82, 40, 40, 942, 942); //MBT SSSR
	//obj playerShell("itemsAll.png", 160, 0, 4, 12, -15, -15); //Снаряд
	//obj playerShell("itemsAll.png", 164, 0, 4, 12, 300, 300); //ПТУР
	//obj playerShell("itemsAll.png", 168, 0, 2, 4, 300, 300); // 30-мм Снаряд
	//MBT player("Tanks.png", 82, 82, 40, 40, 300, 300); //IFV SSSR
	//Tanks player("Tanks.png", 41, 82, 40, 40, 300, 300); //BMPT SSSR
	//Tanks player("Tanks.png", 0, 0, 40, 40, 300, 300); //MBT USA
	//Tanks player("Tanks.png", 41, 0, 40, 40, 300, 300); //IFV USA
	//Tanks player("Tanks.png", 82, 0, 40, 40, 300, 300); //SuperMBT USA


//===================================================// Создание противников
	vector<MBT*>entity; //Вектор противников
	vector<obj*>entityShell; //Вектор снарядов противника

//Заполнение вектора противников и снарядов для них
	int qt_entity = 2; //Переменная количества противников

	for(int i = 0; i < qt_entity; i++)
	{	
		entity.push_back(new MBT("Tanks.png", 0, 0, 40, 40, 32, 32));				
		entityShell.push_back(new obj("itemsAll.png", 160, 0, 6, 15, -15, -15));
	}
//===================================================// 
	RenderWindow window(VideoMode(1280, 1024), "Tanks Game"); //Создание окна
	Clock clock; //Объект времени

	
	while(window.isOpen()) //Основное окно событий
	{
		srand(time(NULL));
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		
		Event close;
		while(window.pollEvent(close))
		{
			if(close.type == Event::Closed)
				window.close();
		}
//===================================================// Выше самое важное, малоизменяемое

//Вызов методов управления игрока
		player->control(time); 
		player->update(time);
		player->interactionWithMap();
		player->fire(playerShell, time, playerAutoShell);

//===================================================// ИИ
	//Спавн нового противника каждые 6 секунд
		float FullTime = 8000; //Переменная разницы времени между созданием и размещением нового противника
		TimeResp += time;
		if(TimeResp >= FullTime)
		{
			Respawn = 1 + rand() % 3;

			//Добавление в вектора противника в одном из 3-х рандомных мест
			if(Respawn == 1)
				entity.push_back(new MBT("Tanks.png", 0, 0, 40, 40, 32, 32));
			if(Respawn == 2)
				entity.push_back(new MBT("Tanks.png", 0, 0, 40, 40, 942, 32));
			if(Respawn == 3)
				entity.push_back(new MBT("Tanks.png", 0, 0, 40, 40, 32, 942));

			//Добавление снаряда для противника
			entityShell.push_back(new obj("itemsAll.png", 160, 0, 6, 15, -15, -15));
			TimeResp = 0;
		}
	//Отрисовка эффектов попаданий
		TimeFire += time;
		if(TimeFire >= 500) //полсекунды на месте попадания остается эффект
		{
			fireGun->sprite.setPosition(-15, -15);		//После переносится за область видимости игрока
			fireAutoGun->sprite.setPosition(-15, -15);	//После переносится за область видимости игрока
			TimeFire = 0;
		}
	//Вызов методов управления для противника
		for(long unsigned int i = 0; i < entity.size(); i++)
		{
			entity[i]->Artificial_Intelligence(time);
			entity[i]->fire(entityShell[i], time, playerAutoShell);
			entity[i]->update(time);
			entity[i]->interactionWithMap();
			entity[i]->dead(playerShell, 942, 32, player->damage, playerAutoShell, player->AutoDamage, fireAutoGun, fireGun);
			player->dead(entityShell[i], 942, 942, entity[i]->damage, fireGun);

	//Проверка противников на уничтожение
			if(entity[i]->isDead == true)
			{
			//Удаление противника и его снаряда
				entity.erase(entity.begin() + i);
				entityShell.erase(entityShell.begin() + i);
				player->Score += 5;
			}
		}

		Score(&text, player->Score, &MaxScore, player->HitPoint, player->isReloading, player->isAutoReloading);
//===================================================//Рисование карты
		for(int i = 0; i < HEIGHT_MAP; i++)
		{
			for(int j = 0; j < WIDHT_MAP; j++)
			{
				MapFunct(&MapObj, i, j);
				window.draw(MapObj.sprite);
			}
		}
//==================================================// Рисуем всё, что есть
		window.draw(player->sprite);				//Рисование игрока
		window.draw(playerShell->sprite);			//Рисование его снаряда

		for(long unsigned int i = 0; i < entity.size(); i++) //Рисовка противника и его снаряда
		{
			window.draw(entity[i]->sprite);
			window.draw(entityShell[i]->sprite);		
		}

		for(long unsigned int i = 0; i < playerAutoShell.size(); i++)
		{
			window.draw(playerAutoShell[i]->sprite);	//Рисование снарядов Автопушки
		}

		window.draw(fireGun->sprite);			//Рисование эффекта Пушки
		window.draw(fireAutoGun->sprite);		//Рисование эффекта автоПушки
		window.draw(playerInf->sprite);			//Рисование окна информации
		window.draw(text);						//Рисование текста

		window.display();
	}
}
