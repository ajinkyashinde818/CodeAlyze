import sys, math
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 10**9 + 7

N = ri()
A = rl()
B = rl()
C = rl()

ans = 0
prev = -2
for i in range(N):
	n = A[i]-1
	ans += B[n]
	if n-prev == 1:
		ans += C[prev]
	prev = n
print(ans)
