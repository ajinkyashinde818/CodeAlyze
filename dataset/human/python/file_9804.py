N,K = map(int,input().split())
A = [0] + list(map(int,input().split()))

from collections import deque 
tmp = 1
num = []
seen = [-1]*(N+1)
 
while seen[tmp] == -1:
    seen[tmp] = tmp
    num.append(tmp)
    tmp = A[tmp]


l = num.index(tmp)
c = len(num) - l

if K < l:
    print(num[K])
else:
    print(num[(K-l)%c+l])
