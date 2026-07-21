import collections
q = collections.deque(list(raw_input()))
operations = [raw_input().split(' ') for _ in range(int(raw_input()))]
rev = False

for op in operations:
	if len(op) == 1:
		rev = not(rev)
	elif len(op) == 3:
		_, where, char = op
		where = bool(int(where) - 1) ^ rev
		if where:			
			q.append(char)
		else:
			q.appendleft(char)

print ''.join(list(q)[:: (-1 if rev else 1)])
