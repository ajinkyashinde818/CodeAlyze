import math
import sys
from collections import Counter

import time

N = int(input())
Ns = N


def create_sosu(n, max, Nso):
    for i in range(2, max+1):
        if n % i == 0:
            while n % i == 0:
                n = n // i
                Nso.append(i)
            return create_sosu(n, int(math.sqrt(n)), Nso)

    # 最後まで来た場合 = その値が素数の場合
    # ただし1は素数ではない
    if n != 1:
        Nso.append(n)
    return Nso


def execute_answer(n, kv):
    # 設問の操作をしていきます
    x = 0
    count = 0
    xcount = 0
    while n > 1 and x <= len(kv):
        for x in kv.keys():
            for y in range(1, kv[x]+1, +1):
                if n % (x**y) == 0:
                    count = count+1
                    n = n//(x**y)
                    xcount = xcount+y
                else:
                    break
    print(count)


def main():

    # Nが1の場合にはそのまま終了
    if N == 1:
        print(0)
        return

    # Nが1以外の場合
    # 素数一覧を作成する
    Nso = create_sosu(N, int(math.sqrt(N)), [])
    execute_answer(Ns, Counter(Nso))


main()
