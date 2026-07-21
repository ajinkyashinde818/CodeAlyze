import math
from collections import Counter



def prime_factorization(num):
    """
    素因数分解
    ;param num 素因数分解したい数字
    ;return result {素因数: 回数, ・・・}
    """

    result = dict()

    N = num

    x = 2
    while x <= int(math.sqrt(num)) + 1:
        if (num % x) == 0:
            count = 0
            while (num % x) == 0:
                count += 1
                num = num / x

            result[x] = count

        x += 1

    if num != 1:
        result[num] = 1

    if result == []:
        result[N] = 1

    return result


N = int(input())

# 素因数分解
result = prime_factorization(N)

# 操作の回数を求める
ans = 0
for value in result.values():
    c = 1
    while (value - c) >= 0:
        ans += 1
        value -= c
        c += 1

print(ans)
