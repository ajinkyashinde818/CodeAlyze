from collections import deque
s=input()
de=deque(list(s))
rev=0
append,appendleft=de.append,de.appendleft
for _ in range(int(input())):
	t=input()
	if t[0]=="1":
		rev^=1
	else:
		_,f,c=t.split()
		if f=="1":
			if rev:
				append(c)
			else:
				appendleft(c)
		else:
			if rev:
				appendleft(c)
			else:
				append(c)
li=list(de)
if rev:
	li=li[::-1]
print("".join(li))
