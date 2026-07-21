import sys
n,m = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(m)]
start = a[0][0]
goal = n
tmp,ans = [],[]
for i in range(m):
	if a[i][1] == goal:
		tmp.append(a[i][0])
#print(tmp)
for j in range(m):
		if a[j][0] == start:
			ans.append(a[j][1])
if len(set(tmp)&set(ans)) > 0:
	print('POSSIBLE')
	sys.exit()
print('IMPOSSIBLE')
