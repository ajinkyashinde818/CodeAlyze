import sys
sys.setrecursionlimit(int(1e6))

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = 0
prev = -1
for a in A:
    i = a - 1
    ans += B[i]
    if (prev + 1) == a:
        ans += C[i-1]
    prev = a

print(ans)
