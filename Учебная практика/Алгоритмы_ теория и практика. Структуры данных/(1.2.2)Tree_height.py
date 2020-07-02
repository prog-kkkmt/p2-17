"""
Высота дерева
Sample Input:
10
9 7 5 5 2 9 9 9 2 -1
Sample Output:
4
"""


def height(arr):
    """
    Функция для определения высоты дерева
    :param arr: Корневое дерево с вершинами {0,...,n−1} ,
    заданное как последовательность parent0,...,parentn−1,где parenti — родитель i-й вершины.
    :return: высота дерева
    """
    d = [-1] * (len(arr)) + [0]

    def count_depth(i):
        """
        Функция для расчёта высоты поддерева
        :param i: вершина
        :return: высота поддерева с корнем в вершине i
        """
        if d[i] == -1:
            d[i] = count_depth(arr[i]) + 1
        return d[i]

    return max(count_depth(i) for i in range(len(arr)))


def main():
    n = int(input())
    arr = [int(el) for el in input().split()][:n]
    print(height(arr))


if __name__ == '__main__':
    main()
