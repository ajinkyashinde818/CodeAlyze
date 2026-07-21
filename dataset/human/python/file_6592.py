from collections import deque
aa = list(map(str, input()))
S = deque()
for a in aa:
	S.append(a)
Q = int(input())
ope = []

for _ in range(Q):
	a = list(map(str, input().split()))
	if len(a) == 1:
		ope.append(a)
	else:
		ope.append(a)
	
# 先頭か末尾かを判定していけばよい
std = True # 順列か否か

for i in range(Q):
	if ope[i][0] == "1":
		std = not std
	else:
		if ope[i][1] == "1": # 先頭に付加
			if std: S.appendleft(ope[i][2])
			else: S.append(ope[i][2])
		else: # 末尾に不可
			if std: S.append(ope[i][2])
			else: S.appendleft(ope[i][2])
		
if std:		
	for s in S:
		print(s, end = "")
else:
	for s in reversed(S):
		print(s, end = "")
