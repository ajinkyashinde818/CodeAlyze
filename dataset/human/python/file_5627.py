import sys

s = list(map(str, input()))

ans = 0
while s:
	if s[0] == s[-1]:
		s.pop(0)
		try:
			s.pop()
		except IndexError:
			break
	elif s[0] == 'x':
		ans += 1
		s.pop(0)
	elif s[-1] == 'x':
		ans += 1
		s.pop()
	else:
		print(-1)
		sys.exit()

print(ans)
