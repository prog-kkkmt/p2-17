#include <stdlib.h>
#include <stdio.h>

struct box{
	char * in_1, *in_2;//Множества 
	int size_1, size_2;//Размер множеств
};

struct data_array{
	char *out;//Множество
	int size_out;//Размер множества
};
struct box get_array();//Получение множеств от пользвателя 
void show(struct data_array data);//Отображение результата 
struct data_array addition(struct box in);//Объединение множеств 
struct data_array disjunction(struct box in);//Пересечение множеств 
bool equality(struct box in);//Проверка на равенство множеств
struct data_array difference(struct box in);//Разность множеств 
struct data_array symmetrical_difference(struct box in);//Симметричная разность множеств
bool subset(struct box in);// Проверка является множество 'B' подмножеством 'A'
