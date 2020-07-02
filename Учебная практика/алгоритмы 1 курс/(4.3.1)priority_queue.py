"""
Выполнил: Филиппов Л. П2-17
Задача:
Первая строка входа содержит число операций 1≤n≤10^5.
Каждая из последующих n строк задают операцию одного из следующих двух типов:
Insert x, где 0≤x≤10^9 — целое число;
ExtractMax.
Первая операция добавляет число x в очередь
с приоритетами, вторая — извлекает максимальное число и выводит его.
"""

import heapq  # импорт библиотеки с кучей


def main():
    """
    Функция для построения минимальной кучи
    и извлечения максимумов
    :return:
    """
    n = int(input())
    queue = []  # очередь
    maxs = []  # массив с максимумами
    for _ in range(n):
        command = input()
        if command.startswith('Insert'):
            _, priority = command.split()
            priority = int(priority)
            heapq.heappush(queue, -priority)
        else:
            maxs.append(heapq.heappop(queue))
    for m in maxs:
        print(-m)


if __name__ == '__main__':
    main()
