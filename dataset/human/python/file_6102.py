import collections
n = int(raw_input())
ais = map(int, raw_input().split(' '))
bis = map(int, raw_input().split(' '))
cis = map(int, raw_input().split(' '))


c = 0
q = collections.deque([])
for a in ais:
	c += bis[a - 1]
	if q:
		p = q.popleft()
		if p + 1== a - 1:
			c += cis[p]
	q.append(a - 1)

print c
