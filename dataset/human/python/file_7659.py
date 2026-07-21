from collections import deque
s = deque()
l = input()
for i in range(len(l)):
	s.append(l[i:i+1])
g = 0
q = int(input())
for i in range(q):
	d = input().split(" ")
	if d[0] == "1":
		if g == 0:
			g = 1
		else:
			g = 0
	if d[0] == "2":
		f = d[1]
		if g == 0:
			if f == "1":
				s.appendleft(d[2])
			else:
				s.append(d[2])
		else:
			if f == "1":
				s.append(d[2])
			else:
				s.appendleft(d[2])
if g == 1:
	s.reverse()
	ans = "".join(s)
	print(ans)
else:
	ans = "".join(s)
	print(ans)
