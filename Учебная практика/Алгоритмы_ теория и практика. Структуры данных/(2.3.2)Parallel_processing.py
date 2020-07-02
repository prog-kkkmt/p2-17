"""
Параллельная обработка
Sample Input:
2 5
1 2 3 4 5
Sample Output:
0 0
1 0
0 1
1 2
0 4
"""

from heapq import heapreplace  # Функция которая удаляет и возвращает самый маленький элемент из кучи, а также
# добавляет новый элемент


def main():
    """
    Функция реализующая параллельную обработку
    """
    n, m = map(int, input().split())
    arr = [(0, i) for i in range(n)]
    res = []
    time = [int(i) for i in input().split()[:m]]
    for i in time:
        res.append(list(reversed(heapreplace(arr, (arr[0][0] + i, arr[0][1])))))
    for j in range(len(res)):
        print(res[j][0], res[j][1])


if __name__ == '__main__':
    main()
