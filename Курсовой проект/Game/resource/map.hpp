#pragma once

using namespace std;
using namespace sf;

//Класс для карты
class MapClass
{
private:
	Image image;		//объект изображения
	Texture texture;	//Объкт текстуры
public:	
	Sprite sprite;		//объет спрайта
	MapClass()
	{
		image.loadFromFile("images/itemsAll.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, 32, 32));
		sprite.setPosition(500, 500);
	}
};

//Размеры карты
const int HEIGHT_MAP = 32;
const int WIDHT_MAP = 32;
//Карта
String TileMap[HEIGHT_MAP] = {
	"00000000000000000000000000000000",
	"0                              0",
	"0                              0",
	"0  000      0000000000   0000  0",
	"0  0        0               0  0",
	"0  0        0               0  0",
	"0           0                  0",
	"0      000000                  0",
	"0           0                  0",
	"0           0                  0",
	"0           00000000000        0",
	"0                              0",
	"0                              0",
	"0            0                 0",
	"0            00   0    000     0",
	"0                 0    000     0",
	"0     0           0    000     0",
	"0     00          0            0",
	"0                 0            0",
	"0                 0            0",
	"0                 0            0",
	"0   000000000000000            0",
	"0                              0",
	"0                              0",
	"0   00000000000000         00000",
	"0                              0",
	"0                              0",
	"0  0                        0  0",
	"0  000                      0  0",
	"0                           0  0",
	"0                           0  0",
	"00000000000000000000000000000000"
};