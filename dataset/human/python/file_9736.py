import sys

N, K = list(map(int, input().split()))
A = [0] + list(map(int, input().split()))

visited = [False] * (N+1)
s = 1

while not visited[s]:
    visited[s] = True
    s = A[s]

a = 1

while a != s:
    K -= 1
    a = A[a]
    if K == 0: 
        print(a)
        sys.exit()

visited = [False] * (N+1)
length = 0
while not visited[s]:
    visited[s] = True
    s = A[s]
    length += 1
    
k = K % length
while k:
    s = A[s]
    k -= 1
    
print(s)
