from collections import deque

s = input()
q = int(input())
b = deque(s)
swc = 0
for i in range(q):
	a = list(map(str, input().split()))
	if a[0] == "1":
		swc += 1
	elif a[1] == "1":
		if swc%2 == 0:
			b.appendleft(a[2])
		else:
			b.append(a[2])
	else:
		if swc%2 == 0:
			b.append(a[2])
		else:
			b.appendleft(a[2])
ans = ""
if swc%2 == 0:
	ans = "".join(list(b))
else:
	ans = "".join(reversed(list(b)))
print (ans)
