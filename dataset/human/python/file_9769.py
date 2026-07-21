from collections import deque
N, K = map(int, input().split())
memo = [-1]*(N+1)
junban = deque()
A = [0]+list(map(int, input().split()))
i = 0
x = 1
while memo[x] < 0:
  junban.append(x)
  memo[x] = i
  x = A[x]
  i += 1
T = i-memo[x]
if K < i:
  print(junban[K])
else:
  print(list(junban)[memo[x]:][(K-memo[x])%T])
