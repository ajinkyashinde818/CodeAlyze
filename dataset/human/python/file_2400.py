from itertools import product
import math

D, G = [int(_) for _ in input().split()]

P = [0] * D
C = [0] * D
for i in range(D):
    P[i], C[i] = [int(_) for _ in input().split()]

V = []
for i in range(D):
    v = P[i] * (i + 1) * 100 + C[i]
    V.append(v)

max_P = sum(P)


def func(bit_pattern):
    score = 0
    tmp = 0
    for i in range(D):
        if bit_pattern[i]:
            score += V[i]
            tmp += P[i]

    if score >= G:
        return tmp

    res = G - score

    for i in reversed(range(D)):
        if not bit_pattern[i]:
            x = math.ceil(res / ((i + 1) * 100))
            if x < P[i]:
                return tmp + x

    return max_P


ans = max_P
for bit_pattern in product(range(2), repeat=10):

    tmp = func(bit_pattern)
    ans = min(ans, tmp)

print(ans)
