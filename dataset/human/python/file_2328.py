D, G = [int(i) for i in input().split()]
P, C = [0] * (D + 1), [0] * (D + 1)
for i in range(D):
    P[i + 1], C[i + 1] = [int(i) for i in input().split()]

def solve(d, g):
    if d <= 0:
        return 1e5

    n = min(g // (d * 100), P[d])
    score = (d * 100) * n
    if n == P[d]:
        score += C[d]

    if score < g:
        n += solve(d - 1, g - score)

    return min(n, solve(d - 1, g))

print(solve(D, G))
