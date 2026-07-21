from sys import stdin
D, G = [int(_) for _ in stdin.readline().rstrip().split()]
P, C = [], []
for _ in range(D):
    p, c = stdin.readline().rstrip().split()
    P.append(int(p))
    C.append(int(c))
res = 1<<29
for bit in range(1<<D):
    s, num = 0, 0
    for i in range(D):
        if ((bit >> i) & 1):
            s += C[i] + P[i] * 100 * (i+1)
            num += P[i]
    if s >= G:
        res = min(res, num)
    else:
        for i in range(D-1, -1, -1):
            if ((bit >> i) & 1):
                continue
            for j in range(P[i]):
                if s >= G:
                    break
                s += 100 * (i+1)
                num += 1
        res = min(res, num)
print(res)
