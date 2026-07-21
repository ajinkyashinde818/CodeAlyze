import numpy as np 
N = int(input())
A =list(map(int, input().strip().split()))
Ap = np.abs(A)
i = 0
m = 0
s = 0
M = np.sum(Ap)
while i <= N - 1:
    if A[i] < 0:
        m += 1
    i += 1
if m % 2 ==0:
    print(M)
else:
    Ma = 0
    while s <= N - 1:
        M1 = M - 2 * Ap[s]
        if M1 >= Ma:
            Ma = M1
        s += 1
    print(Ma)
