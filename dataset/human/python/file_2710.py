D, G = [int(_) for _ in input().split()]
PC = [tuple(int(_) for _ in input().split()) for i in range(D)]
P = [_[0] for _ in PC]
C = [_[1] for _ in PC]

from itertools import product
from math import ceil

INF = 10**20

def calc(pat):
    solved_promlems = 0
    total_score = 0
    left = None
    for e, score, problem_nums, complete_score in zip(pat, range(100, (D+1)*100, 100), P, C):
        if e:
            total_score += score * problem_nums + complete_score
            solved_promlems += problem_nums
        else:
            left = score, problem_nums
    if total_score >= G:
        return solved_promlems
    if left:
        score, problem_nums = left
        n = ceil((G - total_score) / score)
        if 1 <= n < problem_nums:
            return solved_promlems + n
    return INF

result = min(calc(pat) for pat in product((0, 1), repeat=D))

print(result)
