"""
Максимум в скользящем окне
Sample Input 1:
3
2 1 5
1
Sample Output 1:
2 1 5
Sample Input 2:
8
2 7 3 1 5 2 6 2
4
Sample Output 2:
7 7 5 6 6
"""


class Stack:
    """
    Класс для создания стека
    """
    def __init__(self):
        """
        Конструктор класса с созданием списка
        """
        self.items = []

    def push(self, item):
        """
        Функция для вставки элемента в
        основной стек и стек с максимумами
        (сделано через один двумерный список)
        :param item: элемент
        """
        if not self.items:
            self.items.append([item, item])
        else:
            self.items.append([item, max(self.items[-1][1], item)])

    def pop(self):
        """
        Функция удаляет и возвращает последний элемент стека
        :return: последний элемент стека
        """
        return self.items.pop()[0]

    def is_empty(self):
        """
        Функция для вычисления пустой ли стек
        :return: True или False
        """
        return False if self.items else True

    def max(self):
        """
        Функция для вычисления максимального элемента стека
        :return: максимальный элемент стека
        """
        return self.items[-1][1] if not self.is_empty() else -1


class Queue:
    """
    Класс для создания очереди
    """
    def __init__(self):
        """
        Конструктор класса с созданием списка
        """
        self.l_stack = Stack()
        self.r_stack = Stack()

    def push(self, item):
        """
        Функция для вставки элемента в очередь
        :param item: эелемент
        """
        self.l_stack.push(item)

    def pop(self):
        """
        Функция для удаления и возвращения последнего элемента
        очереди
        :return: последний элемент очереди
        """
        if self.r_stack.is_empty():
            while not self.l_stack.is_empty():
                self.r_stack.push(self.l_stack.pop())
        return self.r_stack.pop()

    def max(self):
        """
        Функция для вычисления максимального элемента очереди
        :return: маскимальный элемент очереди
        """
        return max(self.r_stack.max(), self.l_stack.max())


def max_sliding_window(n, m, arr):
    """
    Функция для вычисления максимума в скользящем окне
    :param n: всего элеиентов
    :param m: размер окна в котором надо найти максимум
    :param arr: массив чисел
    :return: максимум
    """
    q = Queue()
    _max = []
    for i in range(m):
        q.push(arr[i])
    _max = [q.max()]
    for i in range(m, n):
        q.push(arr[i])
        q.pop()
        _max.append(q.max())
    return _max


def main():
    n = int(input())
    arr = [int(el) for el in input().split()]
    m = int(input())
    print(" ".join(str(el) for el in max_sliding_window(n, m, arr)))


if __name__ == '__main__':
    main()
