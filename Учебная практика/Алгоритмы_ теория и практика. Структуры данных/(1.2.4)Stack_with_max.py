"""
Стек с поддержкой максимума
Sample Input 1:
5
push 2
push 1
max
pop
max
Sample Output 1:
2
2
Sample Input 2:
5
push 1
push 2
max
pop
max
Sample Output 2:
2
1
Sample Input 3:
10
push 2
push 3
push 9
push 7
push 2
max
max
max
pop
max
Sample Output 3:
9
9
9
9
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

    def max(self):
        """
        Функция для вычисления максимального элемента стека
        :return: максимальный элемент стека
        """
        return self.items[-1][1]


def main():
    st = Stack()
    n = int(input())
    res = []
    for i in range(n):
        command = input()
        if command.startswith('push'):
            i, digit = command.split()
            digit = int(digit)
            st.push(digit)
        elif command == "pop":
            st.pop()
        else:
            res.append(st.max())
    print("\n".join([str(el) for el in res]))


if __name__ == '__main__':
    main()
