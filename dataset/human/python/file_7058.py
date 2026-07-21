from collections import deque
from bisect import bisect_left, bisect_right

s = list(input())
q = int(input())

count = 0
l = []
reverse = []
for i in range(q):
	tmp = list(map(str,input().split()))
	if len(tmp) == 1:
		count += 1
		if len(l) != 0:
			reverse.append(len(l))
	elif tmp[1] == '1':
		l.append([1, tmp[2]])
	elif tmp[1] == '2':
		l.append([2, tmp[2]])

#print(reverse)
#print(l)
for i in range(len(l)):
	#print(bisect_right(reverse,i))
	l[i][0] += len(reverse) - bisect_right(reverse,i)
	l[i][0] %= 2

if count % 2 == 1:
	s = s[::-1]
s = deque(s)

for i in range(len(l)):
	if l[i][0] == 0:
		s.append(l[i][1])
	else:
		s.appendleft(l[i][1])
print("".join(s))
