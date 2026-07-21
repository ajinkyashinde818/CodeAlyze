import numpy as np
k,n = [int(i) for i in input().split()]

A = [int(i) for i in input().split()]

A.sort()

ans_p = A[0] + k - A[-1]

for i in range(n-1):
    cand = A[i+1] - A[i]
    if cand > ans_p:
        ans_p = cand
        
ans = k - ans_p

print(ans)
