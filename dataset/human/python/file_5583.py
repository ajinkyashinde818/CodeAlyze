import collections

s = input()
a = collections.deque(s)
ans = 0
while 1 < len(a):
	if a[0] == a[len(a) - 1]:
		a.popleft()
		a.pop()
	elif a[0] == 'x':
		a.append('x')
		ans += 1
	elif a[len(a) - 1] == 'x':
		a.appendleft('x')
		ans += 1
	else:
		ans = -1
		break
print(ans)
