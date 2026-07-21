import copy 
import numpy as np

N = int(input())

*A, = map(int, input().split())
*B, = map(int, input().split())
*C, = map(int, input().split())


sum    = 0
temp_A = 0
for i in range(len(A)):

    if temp_A+1==A[i] and i!=0:
        sum = sum + C[temp_A-1]
    sum = sum + B[A[i]-1]
    temp_A = A[i]

print(sum)
