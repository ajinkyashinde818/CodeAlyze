import sys, math
input = sys.stdin.readline
rs = lambda: input().strip()
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))
mod = 10**9 + 7

N, K = rl()
A = rl()

edges = {}
for i, a in enumerate(A):
	edges[i] = a-1

mem = {}
k = 0
n = 0
while True:
	if k == K:
		print(n+1)
		exit()
	if n in mem:
		break
	mem[n] = k
	k += 1
	n = edges[n]

p = k-mem[n]
idx = (K - k) % p

for i in range(idx):
	n = edges[n]
print(n+1)
