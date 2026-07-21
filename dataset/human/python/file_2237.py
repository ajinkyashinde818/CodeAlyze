INF = 10**15
def solve(D, G, p, c):
    best = INF
    for mask in range(2**D):
        num = 0
        score = 0
        for i in range(D):
            if (2**i) & mask:
                num += p[i]
                score += 100*(i+1)*p[i] + c[i]
        for i in range(D-1, -1, -1):
            if ((2**i) & mask) == 0:
                if score < G:
                    diff = G - score
                    q = 100*(i+1)
                    num_solve = min(p[i], (diff+q-1)//q)
                    num += num_solve
                    score += q*num_solve
        if score >= G:
            best = min(best, num)
    return best

D, G = map(int, input().split())
p = [0] * D
c = [0] * D
for i in range(D):
    p[i], c[i] = map(int, input().split())
print(solve(D, G, p, c))
