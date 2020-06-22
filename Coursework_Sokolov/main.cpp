/*
Входные данные строка с однасимвальными членами множества без дубликатов  через пробел
*/
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

int main(int argc, char** argv) {
	int action = 0, p = 0;

	struct set Set_A = get_array();//Получение множеств от пользвателя 
	
	struct set Set_B = get_array();//Получение множеств от пользвателя 
	
	while (p != 1){
		
	printf("\n Action: 7 - info");
	
	printf("\n Action =");
	scanf("%d",&action);
	
	switch(action){	// Выбор действия с множествами 
		case 1:
			show(addition(Set_A,Set_B));// Объединение множеств 
			break;
		
		case 2:
			show(disjunction(Set_A,Set_B));//Пересечение множеств 
			break;
			
		case 3:
			printf("\n%d\n",equality(Set_A,Set_B));//Проверка на равенство множеств
			break;
		
		case 4:
			show(difference(Set_A,Set_B));//Разность множеств 
			break;
			
		case 5:
			show(symmetrical_difference(Set_A,Set_B));//Симетричная разность множеств
			break;
			
		case 6: 
			printf("\n%d\n",subset(Set_A,Set_B));// Проверка является множество 'B' подмножеством 'A'
			break;
		
		case 7:
			printf("\n1 - Unionem of sets; 2 - Intersectio of sets; 3 - Checking the equality of sets;");
			printf("\n4 - Difference of sets; 5 - Symmetric difference of sets; 6 - Check if the set 'B' is a subset of 'A';\n8 - exit.\n");
			break;
		
		default : p = 1; return 0;
		break;
	}
	}
	system("pause");
	return 0;
}
