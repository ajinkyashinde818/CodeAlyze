import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))
C = []
num = 0
for i in range(N):
    num += A[i]
    C.append(num)
A.reverse()
D = []
num = 0
for i in range(N):
    num += A[i]
    D.append(num)
D.reverse()
ans = float('inf')
for i in range(0, N - 1):
    ans = min(ans, abs(C[i] - D[i + 1]))
print(ans)
