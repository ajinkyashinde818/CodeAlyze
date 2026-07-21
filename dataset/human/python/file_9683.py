import sys
from _collections import deque
N,K = map(int,input().split())
A = list(map(int,input().split()))
for i in range(len(A)):
    A[i] = A[i]-1
used = [0]*N
m = 0
c = 0
used[m] = 1

while(True):
    m = A[m]
    c += 1
    if c == K:
        print(m+1)
        sys.exit()
    if used[m] == 1:
        break
    else:
        used[m] = 1

loop = m
h = K-c
ans = deque([loop])
c = 0
p = loop
while(True):
    p = A[p]
    c += 1
    if p == loop:
        break
    ans.append(p)

print(ans[h%c]+1)
