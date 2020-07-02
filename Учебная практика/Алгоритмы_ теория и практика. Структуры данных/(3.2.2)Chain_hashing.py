"""
Sample Input 1:
5
12
add world
add HellO
check 4
find World
find world
del world
check 4
del HellO
add luck
add GooD
check 2
del good
Sample Output 1:
HellO world
no
yes
HellO
GooD luck
Sample Input 2:
4
8
add test
add test
find test
del test
find test
find Test
add Test
find Test
Sample Output 2:
yes
no
no
yes
"""


from collections import deque  # импорт очереди


def main():
    """
    Функция реализующая хеширование цепочками
    """
    size = int(input())
    count = int(input())
    x = [1, 263]  # ключи для хеширования
    hash_table = [deque() for i in range(size)]  # создание таблицы хешей
    for i in range(count):
        command = input().split()
        if command[0] == "check":
            print(' '.join(hash_table[int(command[1])]))  # вывод значения запрошенной команды
        else:
            for i in range(len(command[1]) - len(x)):
                x.append((x[-1] * x[1]) % 1000000007)

            chain = hash_table[sum(ord(j) * x for j, x in zip(command[1], x)) % 1000000007 % size]  # создание новой
            # цепочки в таблице
            k = command[1] in chain
            if command[0] == "find":
                print("yes" if k else "no")
            elif not k and command[0] == "add":
                chain.appendleft(command[1])  # добавление нового значения в цепочку
            elif k and command[0] == "del":
                chain.remove(command[1])  # удаление значения из цепочки


if __name__ == '__main__':
    main()
