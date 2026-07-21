import sys
raw_input = sys.stdin.readline
N = int(raw_input())
L = map(int, raw_input().split())
nm = 0
for i in xrange(N):
	if L[i] < 0:
		nm += 1
		L[i] = abs(L[i])

if nm % 2 == 1 :
	print sum(L) - 2 * min(L)
else:
	print sum(L)
