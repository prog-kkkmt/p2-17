#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define in_size 256

struct box get_array(){//Получение множеств от пользвателя 
	char str_1[in_size],str_2[in_size];
	char *token_s1, *token_s2, *last_s1, *last_s2;
	
	struct box in;
	in.size_1 = 0;
	in.size_2 = 0;
	
	printf("Enter sets");
 	printf("\n Set A =");
 	
	gets(str_1);//Получаем строку 
	
	in.in_1 = (char*)malloc(strlen(str_1) * sizeof(int));//Выделяем место под моссив
	
	token_s1 = strtok_r(str_1, " ", &last_s1);
	
	while(token_s1 != NULL)//Записываем строку в массив 
	{
	in.in_1[in.size_1] = *token_s1;
	token_s1 = strtok_r(NULL, " ", &last_s1);
	in.size_1++;
	
	}
	
	printf("\n Set B="); 
	gets(str_2);//Получаем строку 
	
	in.in_2 = (char*)malloc(strlen(str_2) * sizeof(int));//Выделяем место под моссив
	
	token_s2 = strtok_r(str_2, " ", &last_s2);
	
	while(token_s2 != NULL)//Записываем строку в массив
	{
	in.in_2[in.size_2] = *token_s2;
	token_s2 = strtok_r(NULL, " ", &last_s2);
	in.size_2++;
	}
	return in;
	
}

void addition(struct box in){// Объединение множеств
	char *out,*work;
	int size_out=in.size_1,k = 0;
	
	for (int i = 0; i < in.size_2; i++){//Вычисляем размер итогово моссива 
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1){
		size_out++;
		}
		k=0; 
	}
	
	out = (char*)malloc(size_out * sizeof(int));//Выделяем место под моссив
	k = 0; size_out = in.size_1;
	
	for (int i = 0; i < in.size_1; i++) out[i]=in.in_1[i];//Заполняем моссив первым множеством 
	
	for (int i = 0; i < in.size_2; i++)//Заполняем моссив вторым множеством 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1)
		{
			out[size_out]=in.in_2[i];
			size_out++;
		}
		k=0; 
	}
	show(out,size_out);	//отображем результат 
	free(out);//Очищаем память
}

void disjunction(struct box in){//Пересечение множеств 
	char *out,*work;
	int size_out=0;
	
	for (int i = 0; i < in.size_2; i++){//Вычисляем размер итогово моссива 
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] == in.in_2[i]) size_out++;
		} 
	}
	
	out = (char*)malloc(size_out * sizeof(int));//Выделяем место под моссив
	size_out = 0;
	
	for (int i = 0; i < in.size_1; i++) out[i]=in.in_1[i];//Заполняем моссив первым множеством 
	
	for (int i = 0; i < in.size_2; i++)//Заполняем моссив вторым множеством 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_1[j] == in.in_2[i])
			{
			out[size_out]=in.in_2[i];
			size_out++;
			}
		} 
	}
	show(out,size_out);	//отображем результат 
	free(out);//Очищаем память
}

void equality(struct box in){//Проверка на равенство множеств
	int k = 0;
		for (int i = 0; i < in.size_2; i++){//Проверям на равенство по элементно
			for(int j = 0; j < in.size_1; j++){
				if (in.in_1[j] == in.in_2[i]) k++;
			} 
		}
	if (k = in.size_2 && in.size_1 == in.size_2) printf("'A' = 'B'\n");
	else printf("'A' != 'B'\n");
}

void difference(struct box in){//Разность множеств 
	char *out,*work;
	int size_out = 0, k = 0 ;
	
	for (int i = 0; i < in.size_1; i++){//Вычисляем размер итогово моссива 
		for(int j = 0; j < in.size_2; j++){
			if (in.in_1[i] != in.in_2[j]) k++;
		} 
		if (k == in.size_2) size_out++;
		k=0;
	}
	
	out = (char*)malloc(size_out * sizeof(int));//Выделяем место под моссив
	size_out = 0; k = 0;
	
	
	for (int i = 0; i < in.size_1; i++)//Заполняем моссив
	{
		for(int j = 0; j < in.size_2; j++)
		{
			if (in.in_1[i] != in.in_2[j]) k++;
		}
		if(k == in.size_2){
			out[size_out]=in.in_1[i];
			size_out++;
		}
		k = 0; 
	}
	show(out,size_out);	//отображем результат 
	free(out);//Очищаем память
}

void symmetrical_difference(struct box in){//Симетричная разность множеств
	char *out,*work;
	int size_out = 0, k = 0 ;
	
	for (int i = 0; i < in.size_1; i++){//Вычисляем размер итогово моссива ч.1
		for(int j = 0; j < in.size_2; j++){
			if (in.in_1[i] != in.in_2[j]) k++;
		} 
		if (k == in.size_2) size_out++;
		k=0;
	}
	
	for (int i = 0; i < in.size_2; i++){//Вычисляем размер итогово моссива ч.2
		for(int j = 0; j < in.size_1; j++){
			if (in.in_1[j] != in.in_2[i]) k++;
		} 
		if (k == in.size_1) size_out++;
		k=0;
	}
	
	out = (char*)malloc(size_out * sizeof(int));
	size_out = 0; k = 0;
	
	
	for (int i = 0; i < in.size_1; i++)//Заполняем моссив первым множеством 
	{
		for(int j = 0; j < in.size_2; j++)
		{
			if (in.in_1[i] != in.in_2[j]) k++;
		}
		if(k == in.size_2){
			out[size_out]=in.in_1[i];
			size_out++;
		}
		k = 0; 
	}

	for (int i = 0; i < in.size_2; i++)//Заполняем моссив вторым множеством 
	{
		for(int j = 0; j < in.size_1; j++)
		{
			if (in.in_2[i] != in.in_1[j]) k++;
		}
		if(k == in.size_1){
			out[size_out]=in.in_2[i];
			size_out++;
		}
		k = 0; 
	}
	
	show(out,size_out);	//отображем результат 
	free(out);//Очищаем память
}

void subset(struct box in){// Проверка является множество 'B' подмножеством 'A'
	int k = 0;
	
	for (int i = 0; i < in.size_1 ; i++)//Поэлементно сравниваем множества 
		for(int j = 0; j < in.size_2 ; j++){
			if(in.in_1[i] == in.in_2[j]) k++;
		}
	if(k == in.size_2) printf("'B' subset 'A'\n");
	else printf("'B' not a subset 'A'\n");
}

void show(char *out,int n){//Отображение результата 
	printf("\n Set_Out =");
	if (n > 0){
	for(int i = 0; i<n; i++){
    printf("%c ", out[i]);
	}
	printf("\n");
	}
	else printf("Emptu\n");
	free(out);//Очищаем память
}
