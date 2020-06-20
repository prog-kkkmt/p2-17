#include <stdlib.h>
#include <stdio.h>

struct set{
	char *set;//Множество
	int size;//Размер множества
};

struct set get_array();//Получение множеств от пользвателя 
void show(struct set data);//Отображение результата 
struct set addition(struct set Set_A, struct set Set_B);//Объединение множеств 
struct set disjunction(struct set Set_A, struct set Set_B);//Пересечение множеств 
bool equality(struct set Set_A, struct set Set_B);//Проверка на равенство множеств
struct set difference(struct set Set_A, struct set Set_B);//Разность множеств 
struct set symmetrical_difference(struct set Set_A, struct set Set_B);//Симметричная разность множеств
bool subset(struct set Set_A, struct set Set_B);// Проверка является множество 'B' подмножеством 'A'
