"""
Выполнил: Филиппов Л. П2-17
Задача:
По данной непустой строке s длины не более 10^4,
состоящей из строчных букв латинского алфавита,
постройте оптимальный беспрефиксный код. В первой строке
выведите количество различных букв k, встречающихся в строке,
и размер получившейся закодированной строки. В следующих
k строках запишите коды букв в формате "letter: code".
В последней строке выведите закодированную строку.
"""

import heapq  # импорт библиотеки с кучей
from collections import Counter  # импорт counter, чтобы считать количесво неизиеняемых обьектов
from collections import namedtuple  # импорт namedtuple, чтобы создать тип данных, ведущий себя как кортеж


class Node(namedtuple("Node", ["left", "right"])):
    """
    Класс для построения дерева
    """
    def walk(self, code, acc):
        """
        Функция для хождения по дереву
        :param code: словарь для записи
        :param acc: код символа
        :return:
        """
        self.left.walk(code, acc + "0")
        self.right.walk(code, acc + "1")


class Leaf(namedtuple("Leaf", ["char"])):
    """
    Класс листа дерева
    """
    def walk(self, code, acc):
        """
        Функция для присваивания кода данному символу
        :param code: словарь для записи
        :param acc: код символа
        :return:
        """
        code[self.char] = acc or "0"


def huffman_encode(s):
    """
    Функция для постройки оптимального беспрефиксного кода
    :param s: строка
    :return: вывод кодов
    :rtype: dict
    """
    h = []
    for ch, freq in Counter(s).items():
        h.append((freq, len(h), Leaf(ch)))
    heapq.heapify(h)
    count = len(h)
    while len(h) > 1:
        freq1, count1, left = heapq.heappop(h)
        freq2, count2, right = heapq.heappop(h)
        heapq.heappush(h, (freq1 + freq2, count, Node(left, right)))
        count += 1
    code = {}
    if h:
        [(freq, count, root)] = h
        root.walk(code, "")
    return code


def main():
    s = input()
    code = huffman_encode(s)
    encoded = "".join(code[ch] for ch in s)
    print(len(code), len(encoded))
    for ch in sorted(code):
        print("{}: {}".format(ch, code[ch]))
    print(encoded)


if __name__ == "__main__":
    main()
