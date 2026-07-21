from sys import stdin, stdout
from collections import deque

rl = lambda: stdin.readline()
rll = lambda: stdin.readline().split()
rli = lambda: map(int, stdin.readline().split())

INF, NINF = float('inf'), float('-inf')

def main():
	n, k = rli()
	A = list(rli())
	for i in range(n):
		A[i] -= 1
	L, seen = 0, set()
	cycle = deque()
	curr, cnt = 0, 0
	final = 0
	init = 0
	while cnt <= k:
		if cnt == k:
			print(curr + 1)
			return
		seen.add(curr)
		cycle.append(curr)
		L += 1
		curr = A[curr]
		if curr in seen:
			final = curr
			break
		cnt += 1
	while cycle and cycle[0] != final:
		init += 1
		cycle.popleft()
	L = len(cycle)
	last = (k-init) % L
	print(cycle[last] + 1)
	stdout.close()

if __name__ == "__main__":
	main()
