"""
Симуляция обработки сетевых пакетов
Sample Input 1:
1 0
Sample Output 1:
Sample Input 2:
1 1
0 0
Sample Output 2:
0
Sample Input 3:
1 1
0 1
Sample Output 3:
0
"""


class Queue:
    """
    Класс для создания очереди
    """
    def __init__(self):
        """
        Конструктор класса с созданием списка
        """
        self.items = []

    def isEmpty(self):
        """
        Функция для проверки пустая ли очередь
        :return: True или False
        """
        return self.items == []

    def push(self, item):
        """
        Функция для вставки элемента в очередь
        :param item: эелемент
        """
        self.items.insert(0, item)

    def pop(self):
        """
        Функция для удаления и возвращения последнего элемента
        очереди
        :return: последний элемент очереди
        """
        return self.items.pop()

    def peek(self):
        """
        Функция возвращает последний элемент очереди
        :return: последний элемент очереди
        """
        return self.items[-1]

    def size(self):
        """
        Функция возвращает размер очереди
        :return: размер очереди
        """
        return len(self.items)


def main():
    """
    Функция реализующая обработку сетевых пакетов
    """
    q = Queue()  # Обьявление очереди
    time = 0  # обьявление переменной времени
    buf_size, count = map(int, input().split()) # считывание размера буфера и количества пакетов
    for i in range(count):
        arrival, duration = map(int, input().split())
        while not q.isEmpty() and q.peek() <= arrival:
            q.pop()
        if time < arrival:
            print(arrival)
            time = arrival + duration
            q.push(time)
        elif q.size() < buf_size:
            print(time)
            time += duration
            q.push(time)
        else:
            print(-1)


if __name__ == '__main__':
    main()
