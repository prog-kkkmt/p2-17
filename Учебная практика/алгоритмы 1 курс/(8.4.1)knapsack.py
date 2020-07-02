"""
Выполнил: Филиппов Л. П2-17
Задача:
Первая строка входа содержит целые числа 1≤W≤104 и 1≤n≤300 — вместимость рюкзака
и число золотых слитков. Следующая строка содержит n целых чисел 0≤w1,…,wn≤10^5,
задающих веса слитков. Найдите максимальный вес золота, который можно унести в рюкзаке.
"""


def knapsack(capacity, weight, count):
    """
    Функция для нахождения максимальный веса,
    который можно унести в рюкзаке
    :param capacity: вместимость рюкзака
    :param weight: вес слитков
    :param count: количество слитков
    :return: максимальный вес золота
    """
    d = [0] * (capacity + 1)
    for i in range(capacity + 1):
        d[i] = [0] * count

    for i in range(count):
        for j in range(capacity + 1):
            d[j][i] = d[j][i - 1]
            if weight[i] <= j:
                d[j][i] = max(d[j][i], d[j - weight[i]][i - 1] + weight[i])
    return d[capacity][count - 1]


def main():
    capacity, count = map(int, input().split())
    weight = list(map(int, input().split()))
    print(knapsack(capacity, weight, count))


if __name__ == "__main__":
    main()
