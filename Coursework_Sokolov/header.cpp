#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define in_size 256

struct set get_array(){//Получение множеств от пользвателя 
	char str[in_size];
	char *token, *last;
	
	struct set data;
	data.size = 0;
	
	printf("Enter set");
 	printf("\n Set =");
 	
	gets(str);//Получаем строку 
	
	data.set = (char*)malloc(strlen(str) * sizeof(int));//Выделяем место под моссив
	
	token = strtok_r(str, " ", &last);
	
	while(token != NULL)//Записываем строку в массив 
	{
	data.set[data.size] = *token;
	token = strtok_r(NULL, " ", &last);
	data.size++;
	}
	
	return data;
	
}

struct set addition(struct set Set_A, struct set Set_B){// Объединение множеств
	char *work;
	int k = 0;
	struct set data;
	data.size=Set_A.size;
	
	for (int i = 0; i < Set_B.size; i++){//Вычисляем размер итогово моссива 
		for(int j = 0; j < Set_A.size; j++){
			if (Set_A.set[j] != Set_B.set[i]) k++;
		} 
		if (k == Set_A.size){
		data.size++;
		}
		k=0; 
	}
	
	data.set = (char*)malloc(data.size * sizeof(int));//Выделяем место под моссив
	k = 0; data.size = Set_A.size;
	
	for (int i = 0; i < Set_A.size; i++) data.set[i]=Set_A.set[i];//Заполняем моссив первым множеством 
	
	for (int i = 0; i < Set_B.size; i++)//Заполняем моссив вторым множеством 
	{
		for(int j = 0; j < Set_A.size; j++)
		{
			if (Set_A.set[j] != Set_B.set[i]) k++;
		} 
		if (k == Set_A.size)
		{
			data.set[data.size]=Set_B.set[i];
			data.size++;
		}
		k=0; 
	}
	return data; //Возвращаем результат 
	free(data.set);//Очищаем память
}

struct set disjunction(struct set Set_A, struct set Set_B){//Пересечение множеств 
	char *work;
	struct set data;
	data.size = 0;
	
	for (int i = 0; i < Set_B.size; i++){//Вычисляем размер итогово моссива 
		for(int j = 0; j < Set_A.size; j++){
			if (Set_A.set[j] == Set_B.set[i]) data.size++;
		} 
	}
	
	data.set = (char*)malloc(data.size * sizeof(int));//Выделяем место под моссив
	data.size = 0;
	
	for (int i = 0; i < Set_A.size; i++) data.set[i]=Set_A.set[i];//Заполняем моссив первым множеством 
	
	for (int i = 0; i < Set_B.size; i++)//Заполняем моссив вторым множеством 
	{
		for(int j = 0; j < Set_A.size; j++)
		{
			if (Set_A.set[j] == Set_B.set[i])
			{
			data.set[data.size]=Set_B.set[i];
			data.size++;
			}
		} 
	}
	return data; //Возвращаем результат 
	free(data.set);//Очищаем память
}

bool equality(struct set Set_A, struct set Set_B){//Проверка на равенство множеств
	int k = 0;
		for (int i = 0; i < Set_B.size; i++){//Проверям на равенство по элементно
			for(int j = 0; j < Set_A.size; j++){
				if (Set_A.set[j] == Set_B.set[i]) k++;
			} 
		}
	if (k = Set_B.size && Set_A.size == Set_B.size) return true;
	else return false;
}

struct set difference(struct set Set_A, struct set Set_B){//Разность множеств 
	char *work;
	int k = 0 ;
	struct set data;
	data.size = 0;
	
	
	for (int i = 0; i < Set_A.size; i++){//Вычисляем размер итогово моссива 
		for(int j = 0; j < Set_B.size; j++){
			if (Set_A.set[i] != Set_B.set[j]) k++;
		} 
		if (k == Set_B.size) data.size++;
		k=0;
	}
	
	data.set = (char*)malloc(data.size * sizeof(int));//Выделяем место под моссив
	data.size = 0; k = 0;
	
	
	for (int i = 0; i < Set_A.size; i++)//Заполняем моссив
	{
		for(int j = 0; j < Set_B.size; j++)
		{
			if (Set_A.set[i] != Set_B.set[j]) k++;
		}
		if(k == Set_B.size){
			data.set[data.size]=Set_A.set[i];
			data.size++;
		}
		k = 0; 
	}
	return data; //Возвращаем результат 
	free(data.set);//Очищаем память
}

struct set symmetrical_difference(struct set Set_A, struct set Set_B){//Симетричная разность множеств
	char *work;
	int k = 0 ;
		struct set data;
	data.size = 0;
	
	for (int i = 0; i < Set_A.size; i++){//Вычисляем размер итогово моссива ч.1
		for(int j = 0; j < Set_B.size; j++){
			if (Set_A.set[i] != Set_B.set[j]) k++;
		} 
		if (k == Set_B.size) data.size++;
		k=0;
	}
	
	for (int i = 0; i < Set_B.size; i++){//Вычисляем размер итогово моссива ч.2
		for(int j = 0; j < Set_A.size; j++){
			if (Set_A.set[j] != Set_B.set[i]) k++;
		} 
		if (k == Set_A.size) data.size++;
		k=0;
	}
	
	data.set = (char*)malloc(data.size * sizeof(int));
	data.size = 0; k = 0;
	
	
	for (int i = 0; i < Set_A.size; i++)//Заполняем моссив первым множеством 
	{
		for(int j = 0; j < Set_B.size; j++)
		{
			if (Set_A.set[i] != Set_B.set[j]) k++;
		}
		if(k == Set_B.size){
			data.set[data.size]=Set_A.set[i];
			data.size++;
		}
		k = 0; 
	}

	for (int i = 0; i < Set_B.size; i++)//Заполняем моссив вторым множеством 
	{
		for(int j = 0; j < Set_A.size; j++)
		{
			if (Set_B.set[i] != Set_A.set[j]) k++;
		}
		if(k == Set_A.size){
			data.set[data.size]=Set_B.set[i];
			data.size++;
		}
		k = 0; 
	}
	return data; //Возвращаем результат 
	free(data.set);//Очищаем память
}

bool subset(struct set Set_A, struct set Set_B){// Проверка является множество 'B' подмножеством 'A'
	int k = 0;
	
	for (int i = 0; i < Set_A.size ; i++)//Поэлементно сравниваем множества 
		for(int j = 0; j < Set_B.size ; j++){
			if(Set_A.set[i] == Set_B.set[j]) k++;
		}
	if(k == Set_B.size) return true;
	else return false;
}

void show(struct set data){//Отображение результата 
	printf("\n Set_set =");
	if (data.size > 0){
	for(int i = 0; i<data.size; i++){
    printf("%c ", data.set[i]);
	}
	printf("\n");
	}
	else printf("Emptu\n");
	free(data.set);//Очищаем память
}
