import collections
s = map(int,list(raw_input()))
qa = collections.deque([0])
qb = collections.deque([1])
for i in range(len(s)):
	qa.append(min(qa[0] + s[i], qb[0] + 10 - s[i]))
	qb.append(min(qa[0] + s[i] + 1, qb[0] + 10 - s[i] - 1))
	qa.popleft()
	qb.popleft()

print qa[-1]
