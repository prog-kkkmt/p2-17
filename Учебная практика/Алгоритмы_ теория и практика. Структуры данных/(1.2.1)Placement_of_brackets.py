"""
Расстановка скобок в коде
Sample Input 1:
([](){([])})
Sample Output 1:
Success
Sample Input 2:
()[]}
Sample Output 2:
5
Sample Input 3:
{{[()]]
Sample Output 3:
7
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

    def isEmpty(self):
        """
        Функция для проверки пустой ли стек
        :return: True или False
        """
        return self.items == []

    def push(self, item):
        """
        Функция для вставки элемента в стек
        :param item: элемент
        """
        self.items.append(item)

    def pop(self):
        """
        Функция удаляет и возвращает последний элемент стека
        :return: последний элемент стека
        """
        return self.items.pop()

    def size(self):
        """
        Функция возвращает размер стека
        :return: размер стека
        """
        return len(self.items)


def chek_parentheses(s):
    """
    Функция для проверки расстановки скобок
    :param s: строка
    :return: либо первое место, где обнаружена ошибка,
    либо Succes
    """
    sch = 0
    st = Stack()
    brackets = {')': '(', ']': '[', '}': '{'}
    for i, symbol in enumerate(s, 1):
        if symbol in brackets.values():
            st.push(symbol)
            if sch == 0:
                sch = i
        elif symbol in brackets:
            if st.isEmpty() or brackets[symbol] != st.pop():
                return i
            if st.isEmpty():
                sch = 0
    if not st.isEmpty():
        return sch
    else:
        return "Success"


def main():
    s = input()
    print(chek_parentheses(s))


if __name__ == '__main__':
    main()
