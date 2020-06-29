# П2-17 Швыркин А.П.
# Разработать приложение для демонстрации работы АТД"Стек". Использовать модуль.

class Stack:
    """Определение класса Stack"""
    def __init__(self):
        """Объявление стека"""
        self.items = []

    def isEmpty(self):
        """Определяет пустой стек или нет."""
        return self.items == []

    def push(self, item):
        """Добавляет элемент с конца стека."""
        self.items.append(item)

    def pop(self):
        """Удаляет элемент стека с конца"""
        return self.items.pop()

    def peek(self):
        """Вывод последнего элемента стека."""
        if self.isEmpty():
            print("Стек пустой!")
        return self.items[len(self.items) - 1]

    def size(self):
        """Вывод размера стека на экран."""
        return len(self.items)

    def show(self):
        """Вывод содержания стека на экран."""
        return self.items
