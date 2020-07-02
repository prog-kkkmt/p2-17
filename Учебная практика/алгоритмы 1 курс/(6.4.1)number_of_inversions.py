"""
Выполнил: Филиппов Л. П2-17
Задача:
Первая строка содержит число 1≤n≤105, вторая — массив A[1…n],
содержащий натуральные числа, не превосходящие 109.
Необходимо посчитать число пар индексов 1≤i<j≤n, для
которых A[i]>A[j]. (Такая пара элементов называется инверсией массива.
Количество инверсий в массиве является в некотором смысле его мерой
неупорядоченности: например, в упорядоченном по неубыванию массиве
инверсий нет вообще, а в массиве, упорядоченном по убыванию, инверсию
образуют каждые два элемента.)
"""


def merge_sort(arr):
    """
    Функция для разделения массива
    пополам
    :param arr: массив
    :return: отсортированный соединённый массив
    """
    if len(arr) == 1:
        return arr
    mid = len(arr) // 2
    return merge(merge_sort(arr[:mid]), merge_sort(arr[mid:]))


def merge(left, right):
    """
    Функция для сортировки и соединения массива
    :param left: левая часть массива
    :param right: правая часть массива
    :return: отсортированный массив
    """
    arr = []
    global k  # счётчик
    while left and right:
        if left[0] <= right[0]:
            arr.append(left.pop(0))
        else:
            arr.append(right.pop(0))
            k += len(left)
    arr.extend(left or right)
    return arr


def main():
    n = int(input())
    arr = input().split(" ")
    arr = [int(el) for el in arr]
    merge_sort(arr)
    print(k)


if __name__ == '__main__':
    k = 0
    main()
