import itertools
import math

D, G = map(int, input().split())

p = {}
c = {}
s = {}
for i in range(1, D + 1):
    pi, ci = map(int, input().split())
    score = 100 * i * pi + ci
    s[i] = score
    p[i] = pi
    c[i] = ci


def complete(pset):
    score = 0
    solved = 0
    comped = set()
    for i, b in zip(range(1, D + 1), pset):
        if b:
            score += s[i]
            solved += p[i]
            comped.add(i)
    leftset = set(list(range(1, D + 1))) - comped
    return score, solved, leftset


def left(norm, leftset):
    if norm <= 0 or len(leftset) == 0:
        return 0
    i = max(leftset)
    res = int(math.ceil(norm / (100 * i)))
    if res < p[i]:
        return res
    return float("inf")


ans = float("inf")
for pset in itertools.product((True, False), repeat=D):
    score, solved, leftset = complete(pset)
    solved += left(G - score, leftset)
    ans = min(ans, solved)

print(ans)
