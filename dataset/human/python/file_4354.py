from typing import List
from collections import Counter


def prime_factorize(n: int) -> List[int]:
    factor_list = []
    while n % 2 == 0:
        factor_list.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            factor_list.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        factor_list.append(n)
    return factor_list


def count_answer(counter):
    ans = 0
    for count in counter.values():
        i = 1
        while count >= i:
            ans += 1
            count -= i
            i += 1
    return ans


if __name__ == "__main__":
    prime_factors = Counter(prime_factorize(int(input())))
    print(count_answer(prime_factors))
