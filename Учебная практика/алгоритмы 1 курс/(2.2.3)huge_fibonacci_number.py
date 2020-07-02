"""
Выполнил: Филиппов Л. П2-17
Задача:
Даны целые числа 1≤n≤1018 и 2≤m≤105, необходимо найти
остаток от деления n-го числа Фибоначчи на m.
"""


def main():
    """
    Функция для нахождения остатка от
    деления n-го числа Фибоначчи на m
    :param n: n-ое число Фибоначчи
    :param m: число для нахождения остатка
    """
    n, m = map(int, input().split())
    fib_prev = 0  # предыдущее число Фибоначчи
    fib = 1  # следующее число фибоначчи
    cached = [fib_prev, fib]  # массив для хранения чисел Фибоначчи

    for curr in range(1, n):
        fib, fib_prev = (fib + fib_prev) % m, fib

        if fib_prev == 0 and fib == 1:
            cached.pop()
            break
        else:
            cached.append(fib)

    offset = n % len(cached)
    print(str(cached[offset]))  # вывод остатка от деления n-го числа Фибоначчи на m


if __name__ == "__main__":
    main()
