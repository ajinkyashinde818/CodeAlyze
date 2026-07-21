import sys 
try:
	sys.stdin = open('input.txt', 'r') 
	sys.stdout = open('output.txt', 'w')
except:
	pass
input = sys.stdin.readline
for tt in range(1):
	n,k = map(int,input().split())
	l = list(map(int,input().split()))
	cycle = []
	s = set()
	pos = 0
	while True:
		pos = l[pos]-1
		if pos in s:
			start = cycle.index(pos+1)
			break
		cycle.append(pos+1)
		s.add(pos)
	new = cycle[start:]
	size = len(cycle) - len(new)

	if k<=size:
		print(cycle[k-1])
	else:
		k-=size
		print(new[(k-1)%len(new)])
