"""
Поиск образца в тексте
Sample Input 1:
aba
abacaba
Sample Output 1:
0 4
Sample Input 2:
Test
testTesttesT
Sample Output 2:
4
Sample Input 3:
aaaaa
baaaaaaa
Sample Output 3:
1 2 3
"""


def hash(word):
    """
    Функция для хеширования строки
    :param word: строка
    :return: хеш строки
    """
    return sum(ord(l) for l in list(word))


def rabin_karp(s, subs):
    """
    Функция для поиска подстроки в строке с помощью
    алгоритма Карпа–Рабина
    :param s: исходная строка
    :param subs: подстрока
    :return: места вхождения подстроки в строку
    """
    res = []
    hashs = hash(s[:len(subs)])
    hashsub = hash(subs)
    for i in range(0, len(s) - len(subs) + 1):
        next = len(subs) + i
        if i == 0:
            prev = last = 0
        else:
            prev, last = ord(s[i - 1]), ord(s[next - 1])
        hashs = hashs - prev + last
        if hashs == hashsub and subs == s[i:next]:
            res.append(i)
    return res


def main():
    sub = input()
    s = input()
    print(*rabin_karp(s, sub))


if __name__ == '__main__':
    main()
