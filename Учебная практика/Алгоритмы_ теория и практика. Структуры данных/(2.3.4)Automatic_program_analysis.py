"""
Sample Input 1:
4 6 0
1 2
1 3
1 4
2 3
2 4
3 4
Sample Output 1:
1
Sample Input 2:
4 6 1
1 2
1 3
1 4
2 3
2 4
3 4
1 2
Sample Output 2:
0
Sample Input 3:
4 0 6
1 2
1 3
1 4
2 3
2 4
3 4
Sample Output 3:
1
"""


def find(i, parent):
    """
    Функция для поиска корня дерева
    :param i: i-ая вершина
    :param parent: родитель вершины
    :return: корень дерева
    """
    if i != parent[i]:
        parent[i] = find(parent[i], parent)
    return parent[i]


def union_tree(i, j, parent):
    """
    Функция для обьединения деревьев
    :param i: i-ая вершина
    :param j: j-ая вершина
    :param parent: родитель вершины
    :return:
    """
    first, second = find(i - 1, parent), find(j - 1, parent)
    if first != second:
        if second > first:
            parent[second] = first
        else:
            parent[first] = second


def main():
    """
    Функция для проверки равенства вида x_i = x_j и неравенства вида x_p != x_q.
    """
    n, e, d = [int(i) for i in input().split(' ')]
    e_arr = []
    d_arr = []
    for i in range(e):
        i, j = [int(k) for k in input().split()]
        e_arr.append((i, j))
    for i in range(d):
        i, j = [int(k) for k in input().split()]
        d_arr.append((i, j))
    parent = [i for i in range(n)]
    for i in e_arr:
        union_tree(i[0], i[1], parent)
    for i in d_arr:
        if find(i[0] - 1, parent) == find(i[1] - 1, parent):
            print(0)
            return
    print(1)


if __name__ == '__main__':
    main()
