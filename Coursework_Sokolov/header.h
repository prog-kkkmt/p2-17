#include <stdlib.h>
#include <stdio.h>

struct box{
	char * in_1, *in_2;//Множества 
	int size_1, size_2;//Размер множеств
};

struct box get_array();//Получение множеств от пользвателя 
void show(char *out,int n);//Отображение результата 
void addition(struct box in);//Объединение множеств 
void disjunction(struct box in);//Пересечение множеств 
void equality(struct box in);//Проверка на равенство множеств
void difference(struct box in);//Разность множеств 
void symmetrical_difference(struct box in);//Симметричная разность множеств
void subset(struct box in);// Проверка является множество 'B' подмножеством 'A'
