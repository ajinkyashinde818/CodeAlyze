def two_int():
    N, K = map(int, input().split())
    return N,K

def one_int():
    return int(input())

def one_str():
    return input()

def many_int():
    return list(map(int, input().split()))

N=one_int()
A = many_int()

import itertools as it

acc_a = list(it.accumulate(A))

acc_a

maxs = 100000000000
if N>2:
    for i in range(1,len(acc_a)-1):
        if abs((acc_a[-1] - acc_a[i])   - acc_a[i])< maxs:
            maxs=abs(acc_a[-1] - 2*acc_a[i])
else:
    maxs=abs(A[1] - A[0])

print(maxs)
