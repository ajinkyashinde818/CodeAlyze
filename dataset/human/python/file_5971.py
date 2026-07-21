import os, sys, re, math

N = int(input())
A = [int(n) for n in input().split()]
B = [int(n) for n in input().split()]
C = [int(n) for n in input().split()]

s = 0
for i in range(N):
    s += B[A[i] - 1]
    if i > 0 and A[i - 1] == A[i] - 1:
        s += C[A[i - 1] - 1]

print(s)
