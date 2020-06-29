# П2-17 Швыркин А.П.
# Разработать приложение для демонстрации работы АТД"Стек". Использовать модуль.

from stack import Stack # Импорт класса Stack

s=Stack()
choice = ''
while choice != 'Выход': # Switch - case по - питоновски
    choice = input() # Ввод операции
    if choice == '1':
        print(s.isEmpty()) # Проверка на пустоту стека
        print('Введите следующую операцию\n')
    elif choice == '2':
        s.push(input()) # Добавление элемента с конца
        print('Введите следующую операцию\n')
    elif choice == '3':
        s.pop() # Удаление элемента с конца
        print('Введите следующую операцию\n')
    elif choice == '4':
        print(s.peek()) # Вывод последнего элемента стека
        print('Введите следующую операцию\n')
    elif choice == '5':
        print(s.size()) # Вывод размера стека
        print('Введите следующую операцию\n')
    elif choice == '6':
        print(s.show()) # Посмотерть содержимое стека
        print('Введите следующую операцию\n')
    elif choice == 'Выход':
        break
