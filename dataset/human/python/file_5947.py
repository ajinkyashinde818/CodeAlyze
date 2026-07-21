import sys
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
n = INT()
A = LIST()
B = LIST()
C = LIST()
ans = 0
for i in range(n-1):
  if A[i]+1 == A[i+1]:
    ans += C[A[i]-1]
print(ans + sum(B))
