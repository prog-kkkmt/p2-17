"""
Sample Input 1:
12
add 911 police
add 76213 Mom
add 17239 Bob
find 76213
find 910
find 911
del 910
del 911
find 911
find 76213
add 76213 daddy
find 76213
Sample Output 1:
Mom
not found
police
not found
Mom
daddy
Sample Input 2:
8
find 3839442
add 123456 me
add 0 granny
find 0
find 123456
del 0
del 0
find 0
Sample Output 2:
not found
granny
me
not found
"""


def main():
    """
    Функция для реализации структуры данных, эффективно
    обрабатывающую запросы вида: add number name,
    del number и find number
    """
    n = int(input())
    book = {}
    for i in range(n):
        task = input().split()
        if task[0] == "add":
            book[task[1]] = task[2]
        elif task[0] == "find":
            print(book[task[1]] if task[1] in book.keys() else "not found")
        elif task[0] == "del":
            if task[1] in book.keys():
                book.pop(task[1])


if __name__ == '__main__':
    main()
