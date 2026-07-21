import itertools
import numpy as np

D, G = [int(x) for x in input().split()]

level = np.arange(1, D + 1)
P = np.ndarray(D, dtype=int)
C = np.ndarray(D, dtype=int)
for i in range(D):
    P[i], C[i] = [int(x) for x in input().split()]

complete_scores = level * 100 * P + C

min_problems = P.sum()
for bits in itertools.product([0, 1], repeat=D):
    bits = np.array(bits)
    score_rest = G - (bits * complete_scores).sum()
    if score_rest <= 0:
        min_problems = min(min_problems, (bits * P).sum())
    else:
        for i in reversed(range(D)):
            n_problems = (score_rest + (level[i] * 100) - 1) // (level[i] * 100)
            if bits[i] == 0 and n_problems < P[i]:
                min_problems = min(min_problems, (bits * P).sum() + n_problems)
                break

print(min_problems)
