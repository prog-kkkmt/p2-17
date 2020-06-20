#include <stdlib.h>
#include <stdio.h>

struct container_sets{
	char * Set_A, *Set_B;//Множества 
	int size_A, size_B;//Размер множеств
};

struct container_resulting_set{
	char *resulting_set;//Множество
	int resulting_set_size;//Размер множества
};
struct container_sets get_array();//Получение множеств от пользвателя 
void show(struct container_resulting_set data);//Отображение результата 
struct container_resulting_set addition(struct container_sets in);//Объединение множеств 
struct container_resulting_set disjunction(struct container_sets in);//Пересечение множеств 
bool equality(struct container_sets in);//Проверка на равенство множеств
struct container_resulting_set difference(struct container_sets in);//Разность множеств 
struct container_resulting_set symmetrical_difference(struct container_sets in);//Симметричная разность множеств
bool subset(struct container_sets in);// Проверка является множество 'B' подмножеством 'A'
