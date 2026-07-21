import sys
input = sys.stdin.readline
k,n = map(int,input().split())
A = list(map(int,input().split()))

B = [k+A[0]-A[-1]]
for i in range(n-1):
    B.append(A[i+1]-A[i])
print(k-max(B))
