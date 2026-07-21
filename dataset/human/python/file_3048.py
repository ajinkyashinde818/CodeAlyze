import numpy as np


def factorize(N):
    up = int(np.sqrt(N))+2
    out = {}

    for i in range(2,up):
        if N%i == 0:
            temp = N
            count = 0
            while(True):
                N = N//i
                count += 1
                if N%i != 0:
                    break
            out[i] = count
        else:
            continue
    if N != 1:
        out[N] = 1
    return out

n = int(input())
f = factorize(n)
# print(f)

ans = 0
base = 1
for key in f.keys():
    while f[key] >= base:
        ans += 1
        f[key]-= base
        base += 1
    base = 1
print(ans)
