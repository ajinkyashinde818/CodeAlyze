import sys

N, K = map(int, input().split())
A = list(map(int, input().split()))
B = [0]*len(A)

i = 0
c = 0
while K > 0:
    if B[i] == 0:
        B[i] = c
        j = A[i] - 1
        i = j
        K -= 1
        c += 1
    else:
        x = c - B[i]
        K = K % x
        B = [0]*len(A)

print(j + 1)
