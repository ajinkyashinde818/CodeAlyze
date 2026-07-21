import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
K,N = map(int,readline().split())
A = list(map(int,readline().split()))
A = sorted(A)
A.append(A[0]+K)
max_dist = 0
ans = 0
for i in range(N):
    dist = A[i+1] - A[i]
    max_dist = max(max_dist,dist)
    ans += dist
print(ans-max_dist)
