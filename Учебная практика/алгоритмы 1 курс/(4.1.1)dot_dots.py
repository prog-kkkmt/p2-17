"""
Выполнил: Филиппов Л. П2-17
Задача:
По данным n отрезкам необходимо найти
множество точек минимального размера,
для которого каждый из отрезков содержит хотя бы одну из точек.
"""


def search_dots(arr):
    """
    Функция для нахождения множества точек минимального
    размера, для которого каждый из отрезков содержит
    хотя бы одну из точек
    :param arr: множество точек
    """
    arr = sorted(arr, key=lambda x: x[1])
    res = [arr[0][1]]  # массив точек, которые подходят по условию
    for i in range(1, len(arr)):
        if arr[i][0] > max(res):
            res.append(arr[i][1])
    print(len(res))  # вывод количества точек
    print(" ".join([str(elem) for elem in res]))  # вывод точек


def main():
    n = int(input())
    arr_dots = []
    for i in range(n):
        x, y = map(int, input().split())
        arr_dots.append([x, y])
    search_dots(arr_dots)


if __name__ == "__main__":
    main()
