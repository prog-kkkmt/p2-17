"""
Построение кучи
Sample Input 1:
6
0 1 2 3 4 5
Sample Output 1:
0
Sample Input 2:
6
7 6 5 4 3 2
Sample Output 2:
4
2 5
1 4
0 2
2 5
"""


res = []


def swap(i, j, arr):
    """
    Функция для обмена значений двух переменных
    :param i: i-ая позиция элемента
    :param j: j-ая позиция элемента
    :param arr: массив чисел
    """
    arr[i], arr[j] = arr[j], arr[i]


def construction(i, arr):
    """
    Функция для построения кучи
    :param i: i-ый элемент массива
    :param arr: массив чисел
    """
    if 2 * i + 2 < len(arr) and arr[2 * i + 2] < arr[2 * i + 1] and arr[i] > arr[i * 2 + 2]:
        res.append([i, i * 2 + 2])
        swap(i, i * 2 + 2, arr)
        construction(2 * i + 2, arr)
    elif 2 * i + 1 < len(arr) and arr[2 * i + 1] < arr[i]:
        res.append([i, i * 2 + 1])
        swap(i, i * 2 + 1, arr)
        construction(2 * i + 1, arr)


def main():
    n = int(input())
    arr = [int(el) for el in input().split()][:n]
    for i in range(len(arr) - 1, -1, -1):
        construction(i, arr)

    if not res:
        print(0)
    else:
        print(len(res))
        for i in range(len(res)):
            print(res[i][0], res[i][1])


if __name__ == '__main__':
    main()
