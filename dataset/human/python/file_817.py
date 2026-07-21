import sys
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 10**9 + 7

N, R = rl()

ans = R
if N < 10:
	ans += 100 * (10-N)
print(ans)
