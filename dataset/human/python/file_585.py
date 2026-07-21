import numpy as np
def solve(n, a):
    b = np.abs(a)
    num = 0
    for i in range(n):
        if a[i] < 0:
            num += 1
    if num % 2 == 0:
        return np.sum(b)
    else:
        return np.sum(b) - 2*np.min(b)

n = int(input())
a = list(map(int, input().split()))
print(solve(n, a))
