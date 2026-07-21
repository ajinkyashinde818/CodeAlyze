import numpy as np


def solve():
    dists = np.zeros(n, dtype=int)
    for i in range(n):
        dists[i] = abs(a[(i+1)%n]-a[i%n])
        dists[i] = min(dists[i], k-dists[i])
    ans = k - np.max(dists)
    print(ans)
    return




k, n = [int(i) for i in input().split(" ")]
a = [int(i) for i in input().split(" ")]
solve()
