from sets import Set

def solve():
	n, m = map(int, raw_input().split())
	to1 = Set()
	toN = Set()

	for i in range(m):
		x, y = map(int, raw_input().split())
		if x == 1:
			to1.add(y)
		if x == n:
			toN.add(y)
		if y == 1:
			to1.add(x)
		if y == n:
			toN.add(x)

	for i in range(n):
		if i in to1 and i in toN:
			print "POSSIBLE"
			return
			
	print "IMPOSSIBLE"

solve()
