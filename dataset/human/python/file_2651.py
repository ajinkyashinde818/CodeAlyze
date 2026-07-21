import math

D,G = map(int,input().split())
d = [list(map(int,input().split())) for i in range(D)]

A = []
for i in range(D):
    A.append(100*(i+1)*d[i][0] + d[i][1])

ans = 0
for i in range(D):
    ans += d[i][0]

for i in range(2**D):
    a = 0
    g = 0
    B = []
    for j in range(D):
        if (i >> j) & 1:
            a += A[j]
            g += d[j][0]
        else:
            B.append(j)
    b = 0
    for j in B:
        b = max(b,A[j])

    if G-b < a < G+b:
        c = max(B)
        e = math.ceil((G-a)/(100*(c+1)))
        if e <= 0:
            ans = min(ans,g)
        elif e > d[c][0]:
            continue
        else:
            ans = min(ans,g+e)

print(ans)
