import bisect
from operator import itemgetter

d, g = map(int, input().split())
g //= 100
problem_quantities = []
complete_scores = []
for i in range(1, d + 1):
    p, c = map(int, input().split())
    c //= 100
    problem_quantities.append(p)
    complete_scores.append(i * p + c)

curr_idx = d
curr_bit = 0
curr_cmp, curr_qtt = 0, 0
complete_combinations = [None] * (1 << d)
complete_combinations[0] = (0, 0, 0)
for use in range(1, 1 << d):
    if use & curr_bit == 0:
        curr_idx -= 1
        curr_bit = use
        curr_cmp = complete_scores[curr_idx]
        curr_qtt = problem_quantities[curr_idx]
    ps, pq, _ = complete_combinations[use ^ curr_bit]
    complete_combinations[use] = (ps + curr_cmp, pq + curr_qtt, use)

complete_combinations.sort()

bi = bisect.bisect(complete_combinations, (g,))

ans = float('inf')
for s, p, use in complete_combinations[:bi]:
    i = d
    while use & 1:
        i -= 1
        use >>= 1
    cmp = complete_scores[i - 1]
    remain = g - s
    if remain >= cmp:
        continue
    q = min(problem_quantities[i - 1], (remain - 1) // i + 1)
    ans = min(ans, p + q)

ans = min(ans, min(map(itemgetter(1), complete_combinations[bi:])))
print(ans)
