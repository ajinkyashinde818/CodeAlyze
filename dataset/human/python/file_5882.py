import sys
sys.setrecursionlimit(10**6)
n = int(input())
readline = sys.stdin.readline
A = [int(i)-1 for i in readline().split()]
B = [int(i) for i in readline().split()]
C = [int(i) for i in readline().split()]

ans = 0
a_prev = -100
for a in A:
    ans += B[a]
    if a == a_prev+1:
        ans += C[a-1]
    a_prev = a
print(ans)
