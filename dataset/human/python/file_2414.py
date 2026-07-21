from itertools import product
D, G = map(int, input().split())
P, C = map(list, zip(*[tuple(map(int, input().split())) for _ in range(D)]))
CP = [100*i*p+c for i, (p, c) in enumerate(zip(P, C), 1)]
ans = 10**9
for prod in product((True, False), repeat=D):
    I = [i for i, p in enumerate(prod) if p]
    A = sum(CP[i] for i in I)
    r = sum(P[i] for i in I)
    if A >= G:
        ans = min(ans, r)
    else:
        j = max(i for i, p in enumerate(prod) if not p)
        if G > A + 100*(j+1)*(P[j]-1):
            continue
        ans = min(ans, r + (G-A-1)//((j+1)*100)+1)
print(ans)
