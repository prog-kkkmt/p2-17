"""
Sample Input:
5 5
1 1 1 1 1
3 5
2 4
1 4
5 4
5 3
Sample Output:
2
2
3
5
5
"""


def find(i, tables_high):
    """
    Функция для поиска корня дерева
    :param i: i-ый эелемент дерева
    :param tables_high: размеры таблиц
    :return: корень дерева
    """
    if tables_high[i][1] == -1:
        return i
    tables_high[i][1] = find(tables_high[i][1], tables_high)
    return tables_high[i][1]


def main():
    """
    Функция для обьединения двух деревьев
    """
    n, m = map(int, input().split())
    _max = 0
    tables_high = []
    for el in input().split():
        tables_high.append([int(el), -1])
        _max = max(_max, int(el))
    res = []
    for i in range(m):
        first_t, second_t = map(int, input().split())
        first_t, second_t = find(first_t - 1, tables_high), find(second_t - 1, tables_high)
        if first_t != second_t:
            tables_high[first_t][0] += tables_high[second_t][0]
            tables_high[second_t] = [0, first_t]
            _max = max(_max, tables_high[first_t][0])
        res.append(_max)
    for el in res:
        print(el)


if __name__ == '__main__':
    main()
