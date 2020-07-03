#include "set_dll.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <QString>
#include <QStringList>
#include<QDebug>

Set_dll::Set_dll()
{
}

void Set_dll::test(){
    qDebug()<<"Hi";
}

Set_dll Set_dll::get_set(QString text){
    QRegExp rx(" ");
    QStringList query = text.split(rx);
    Set_dll data;

    query.removeDuplicates();
    data.set = (char*)malloc(query.size() * sizeof(int));
    data.size = query.size();

    for(int i = 0; i < query.size(); i++){
        data.set[i] = *query.value(i).toUtf8().data();
        qDebug() << data.set[i];
        }
    return data;
    free(data.set);//Очищаем память
}

QString Set_dll::get_text(Set_dll data){
    QString text ="Получено множество: ";
    for(int i = 0; i < data.size; i++) text = text + data.set[i]+" ";
    return text;
}

Set_dll Set_dll::addition(Set_dll Set_A, Set_dll Set_B){// Объединение множеств
    int k = 0;
    Set_dll data;
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

    data.set = (char*)malloc(data.size * sizeof(int));//Выделяем место под массив
    k = 0; data.size = Set_A.size;

    for (int i = 0; i < Set_A.size; i++) data.set[i]=Set_A.set[i];//Заполняем массив первым множеством

    for (int i = 0; i < Set_B.size; i++)//Заполняем массив вторым множеством
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

Set_dll Set_dll::disjunction(Set_dll Set_A, Set_dll Set_B){//Пересечение множеств
    Set_dll data;
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

bool Set_dll::equality(Set_dll Set_A, Set_dll Set_B){//Проверка на равенство множеств
    int k = 0;
        for (int i = 0; i < Set_B.size; i++){//Проверям на равенство по элементно
            for(int j = 0; j < Set_A.size; j++){
                if (Set_A.set[j] == Set_B.set[i]) k++;
            }
        }
   return (k == Set_B.size && Set_A.size == Set_B.size);
}

Set_dll Set_dll::difference(Set_dll Set_A, Set_dll Set_B){//Разность множеств
    int k = 0 ;
    Set_dll data;
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

Set_dll Set_dll::symmetrical_difference(Set_dll Set_A, Set_dll Set_B){//Симетричная разность множеств
    int k = 0 ;
        Set_dll data;
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

bool  Set_dll::subset(Set_dll Set_A, Set_dll Set_B){// Проверка является множество 'B' подмножеством 'A'
    int k = 0;

    for (int i = 0; i < Set_A.size ; i++)//Поэлементно сравниваем множества
        for(int j = 0; j < Set_B.size ; j++){
            if(Set_A.set[i] == Set_B.set[j]) k++;
        }
    return k == Set_B.size;
}
