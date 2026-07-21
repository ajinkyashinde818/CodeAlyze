from itertools import product
import numpy as np

d, g = map(int, input().split())
p = np.empty(d, dtype=np.int64)
c = np.empty(d, dtype=np.int64)
for i in range(d):
    p[i], c[i] = map(int, input().split())

scores = np.array([p[i] * 100 * (i + 1) + c[i] for i in range(d)], dtype=np.int64)

ans = 10 ** 9
for permutation in product([0, 1], repeat=d):
    permutation = np.array(permutation, dtype=np.int64)
    score = np.inner(scores, permutation)
    problems = np.inner(p, permutation)
    if score >= g:
        ans = min(ans, problems)
    else:
        to_solve = np.max(np.where(permutation == 0))
        extra = -(-(g - score) // (100 * (to_solve + 1)))
        if extra < p[to_solve]:
            ans = min(ans, problems + extra)
print(ans)
