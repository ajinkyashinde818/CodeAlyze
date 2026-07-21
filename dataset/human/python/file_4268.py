import numpy as np


def count(a):
    i = 0
    while a > 0:
        i += 1
        a -= i
        if a == 0:
            break
        if a < 0:
            i -= 1
            break
    return i


def main(N):
    num = N
    ans = 0
    A = np.zeros((1000000), np.int32)
    i = 2
    last = 0
    if N == 1:
        return 0
    while True:
        if num % i == 0:
            num = num//i
            A[i] += 1
        else:
            i += 1
            if num == 1:
                break
            if i*i > num:
                last = 1
                break
    for j in range(i):
        ans += count(A[j])
    ans += last
    return ans


N = int(input())
print(main(N))
