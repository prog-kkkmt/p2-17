"""
Выполнил: Филиппов Л. П2-17
Задача:
Вычислите расстояние редактирования двух данных непустых
строк длины не более 102, содержащих строчные буквы латинского алфавита.
"""


def editing_distance(a, b):
    """
    Функция для вычисления расстояния редоктирования
    :param a: изначальная строка
    :param b: строка для редактирования
    :return: расстояние редактирования
    """
    n, m = len(a), len(b)
    if n > m:
        a, b = b, a
        n, m = m, n
    cur = range(n + 1)
    for i in range(1, m + 1):
        prev, cur = cur, [i] + [0] * n
        for j in range(1, n + 1):
            add, delete, change = prev[j] + 1, cur[j - 1] + 1, prev[j - 1]
            if a[j - 1] != b[i - 1]:
                change += 1
            cur[j] = min(add, delete, change)
    return cur[n]


def main():
    first_str = input()
    second_str = input()
    print(editing_distance(first_str, second_str))


if __name__ == "__main__":
    main()
