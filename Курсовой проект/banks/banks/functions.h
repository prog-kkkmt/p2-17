#pragma once
void getff(); //данные из файла в вектор
void print(); //вывод таблы с данными на экран
void vector_to_file(); //запись таблицы с данными в файл "filename"
double get_commission(); //получение комиссии из файла "commissionFileName"
int choice_your_destiny(); //функция выбора номера валюты
void add_field(); // добавление поля
void edit_field(); // изменение курса валюты у поля
void delete_field(); //удаление поля
void change_field(); // изменение поля
void change_password(); //смена пароля
void change_commission(); //изменение комиссии
void worker_menu(); // меню для работника
void worker(); // проверка пароля и доступ к режиму редактирования данных
long double calculate_sum(double coins, double value, double commission); //вычисление итогового счёта
void clear_buf(); //очистка буфера ввода