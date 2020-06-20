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
void choice(int &a)
{
	RenderWindow window(VideoMode(320, 136), "Choice Tanks"); //Рисуем отдельное окно
	Clock clock;

	vector<obj*> choicePlayer;
	choicePlayer.push_back(new obj("itemsAll.png", 0, 187, 100, 136, 0, 0));
	choicePlayer.push_back(new obj("itemsAll.png", 100, 187, 100, 136, 110, 0));
	choicePlayer.push_back(new obj("itemsAll.png", 200, 187, 100, 136, 220, 0));

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
			else if(Mouse::isButtonPressed(Mouse::Left))
			{
				if(choicePlayer[0]->sprite.getGlobalBounds().contains(pos.x, pos.y))
					{
						a = 1;
						window.close();
					}
				if(choicePlayer[1]->sprite.getGlobalBounds().contains(pos.x, pos.y))
					{
						a = 2;
						window.close();
					}
				if(choicePlayer[2]->sprite.getGlobalBounds().contains(pos.x, pos.y))
					{
						a = 3;
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
	font.loadFromFile("resourse/9303.ttf");
	Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::White);


	MapClass MapObj; //Объект карты

	Tanks *player; //Объект игрока
	obj* playerShell; //Объект снаряда игрока
	obj* playerInf = new obj("Buttons.png", 443, 2, 251, 280, 1026, 730); //Окно основной информации
	vector<obj*> playerBMPT; //Объект 30-мм снарядов игрока

	obj* fireAutoGun = new obj("itemsAll.png", 160, 20, 10, 10, 300, 300); //Объект эффекта попадания от АвтоПушки
	obj* fireGun = new obj("itemsAll.png", 173, 21, 15, 15, 400, 400); //Объект эффекта попадания от снаряда

	int i; //Переменная выбора танчика
	int MaxScore = 0; //Переменная максималных очкнов
	int Respawn = 0; //Переменная спавна противника
	float TimeResp = 0; //Переменная времени спавна противника
	float TimeFire = 0; //Переменная времени стрельбы противником
	choice(i); //Вызов фунции выбора

//===================================================//Создание танчика по выбору игрока
	if(i == 1)
	{
		MBT* ptanks = new MBT("Tanks.png", 0, 82, 40, 40, 942, 942);
		obj* pShell = new obj("itemsAll.png", 160, 0, 6, 15, -15, -15);
		player = ptanks;
		playerShell = pShell;
	}
	else if(i == 2)
	{
		BMPT* ptanks = new BMPT("Tanks.png", 41, 82, 40, 40, 942, 942);
		obj* pShell = new obj("itemsAll.png", 167, 0, 6, 18, -15, -15);
		player = ptanks;
		playerShell = pShell;

		for(int i = 0; i < 5; i++)
			playerBMPT.push_back(new obj("itemsAll.png", 172, 0, 4, 6, 300, 300));
	}
	else if(i == 3)
	{
		IFV* ptanks = new IFV("Tanks.png", 82, 82, 40, 40, 942, 942);
		obj* pShell = new obj("itemsAll.png", 160, 0, 6, 18, -15, -15);
		player = ptanks;
		playerShell = pShell;

		for(int i = 0; i < 5; i++)
			playerBMPT.push_back(new obj("itemsAll.png", 172, 0, 4, 6, 300, 300));
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

	for(int i = 0; i < 1; i++)
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
		player->fire(playerShell, time, playerBMPT);

//===================================================// ИИ
	//Спавн нового противника каждые 6 секунд
		TimeResp += time;
		if(TimeResp >= 8000)
		{
			Respawn = 1 + rand() % 3;
			if(Respawn == 1)
				entity.push_back(new MBT("Tanks.png", 0, 0, 40, 40, 32, 32));
			if(Respawn == 2)
				entity.push_back(new MBT("Tanks.png", 0, 0, 40, 40, 942, 32));
			if(Respawn == 3)
				entity.push_back(new MBT("Tanks.png", 0, 0, 40, 40, 32, 942));

			entityShell.push_back(new obj("itemsAll.png", 160, 0, 6, 15, -15, -15));
			TimeResp = 0;
		}
	//Стрельба касетных снарядов автопушки игрока каждые полсекунды
		TimeFire += time;
		if(TimeFire >= 500)
		{
			fireGun->sprite.setPosition(-15, -15);
			fireAutoGun->sprite.setPosition(-15, -15);
			TimeFire = 0;
		}
	//Вызов методов управления для противника
		for(long unsigned int i = 0; i < entity.size(); i++)
		{
			entity[i]->Artificial_Intelligence(time);
			entity[i]->fire(entityShell[i], time, playerBMPT);
			entity[i]->update(time);
			entity[i]->interactionWithMap();
			entity[i]->dead(playerShell, 942, 32, player->damage, playerBMPT, player->AutoDamage, fireAutoGun, fireGun);
			player->dead(entityShell[i], 942, 942, entity[i]->damage, fireGun);

			if(entity[i]->isDead == true)
			{
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
		window.draw(player->sprite);
		window.draw(playerShell->sprite);

		for(long unsigned int i = 0; i < entity.size(); i++) //Удаление противника и его снаряда
		{
			window.draw(entity[i]->sprite);
			window.draw(entityShell[i]->sprite);		
		}

		for(long unsigned int i = 0; i < playerBMPT.size(); i++)
		{
			window.draw(playerBMPT[i]->sprite);
		}

		window.draw(fireGun->sprite);
		window.draw(fireAutoGun->sprite);
		window.draw(playerInf->sprite);
		window.draw(text);

		window.display();
	}
}