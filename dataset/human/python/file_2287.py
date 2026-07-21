D, G = map(int, input().split())
X = []
for i in range(D):
    p, c = map(int, input().split())
    X.append((p, c))

def calc(k):
    s = G
    a = 0
    for i in range(D):
        if k & (1<<i):
            a += X[i][0]
            s -= X[i][0] * (i+1) * 100 + X[i][1]
    if s <= 0:
        return a
    for i in range(D)[::-1]:
        if k & (1<<i) == 0:
            if s > X[i][0] * (i+1) * 100:
                return 1<<100
            else:
                a += -(-s//((i+1) * 100))
                break
    return a

mi = 1 << 100
for j in range(1<<D):
    mi = min(mi, calc(j))
print(mi)
