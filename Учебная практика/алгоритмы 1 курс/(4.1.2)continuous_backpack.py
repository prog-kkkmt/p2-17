"""
Выполнил: Филиппов Л. П2-17
Задача:
Первая строка содержит количество предметов 1≤n≤103 и
вместимость рюкзака 0≤W≤2⋅10^6. Каждая из следующих n
строк задаёт стоимость 0≤ci≤2⋅10^6 и объём 0<wi≤2⋅10^6
предмета (n, W, ci, wi — целые числа). Выведите максимальную
стоимость частей предметов (от каждого предмета можно отделить
любую часть, стоимость и объём при этом пропорционально уменьшатся),
помещающихся в данный рюкзак, с точностью не менее трёх знаков после запятой.
"""


def calculation(arr, max_weight):
    """
    Функция для определения максимальной стоимости
    частей предметов помещающихся в рюкзак
    :param arr: массив со стоимостью и обьёмами предметов
    :param max_weight: максимальный обьём рюкзака
    :return:
    """
    order = [(v / w, w) for v, w in arr]  # Массив с удельной стоимостью и массой
    order.sort(reverse=True)
    sch = 0  # счётчик
    for v_w, w in order:
        if w < max_weight:
            sch += v_w * w
            max_weight -= w
        else:
            sch += v_w * max_weight
            break
    print('{:.3f}'.format(sch))  # вывод максимальной стоимости


def main():
    n, max_weight = map(int, input().split())
    arr = []
    for i in range(n):
        c, w = map(int, input().split())
        arr.append([c, w])
    calculation(arr, max_weight)


if __name__ == "__main__":
    main()
