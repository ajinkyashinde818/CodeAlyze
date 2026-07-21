import numpy as np

N = int(input())
A = list(map(int,input().split()))

minus = 0

minim = 100000000

for i,v in enumerate(A):
    if v < 0 :
        minus += 1
        A[i] = -v
    minim = min(minim,A[i])

if minus % 2 == 0:
    print(sum(A))
else:
    print(sum(A) - 2 * minim)
