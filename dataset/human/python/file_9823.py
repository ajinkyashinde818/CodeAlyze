import numpy as np
N, K = (int(i) for i in input().split())  
A = [int(i) - 1 for i in input().split()] 
N = len(A)

def get_keys_from_value(d, val):
    return [k for k, v in d.items() if v == val][0]

now = 0
lis = []
p = {}
for i in range(N):
  now = A[now]
  if now in p:
    break
  
  p[now] = i
  lis.append(now)

if K < i:
  print(lis[K-1] + 1)
else:
  print(lis[(K-i-1) % (i - p[now]) + p[now]] + 1)
