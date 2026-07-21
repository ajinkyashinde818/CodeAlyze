import numpy as np
import heapq

N = int(input())
A = list(map(int,input().split()))

if len([i for i in A if i < 0]) % 2 == 0:
    A = np.abs(A)
    ans = sum(A)
else:
    A = np.abs(A)
    A = list(A)
    heapq.heapify(A)
    a = heapq.heappop(A)
    ans = sum(A) - a
print(ans)
