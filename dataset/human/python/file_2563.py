import sys
if sys.platform =='ios':
	sys.stdin=open('Untitled.txt')
input = sys.stdin.readline

D, G = map(int, input().split())
pd = []
for i in range(D):
	pd.append(list(map(int, input().split())))

#print(pd)
N = len(pd)

p_effort = []
for i in range(len(pd)):
	p_effort.append([pd[i][0], pd[i][0]*(i+1)*100+pd[i][1]])
#print(p_effort)

bonus_pattern = []
for i in range(2**N):
	bonus = [0] * N
	for j in range(N):
		if (i>>j & 1):
			bonus[N-j-1] = 1
	bonus_pattern.append(bonus)
#print(bonus_pattern)

ans = []
for bp in bonus_pattern:
	total,effort = 0,0
	for i in range(len(bp)):
		if bp[i] == 1:
			total += p_effort[i][1]
			effort += p_effort[i][0]
	#print(bp, total, effort)
	if total < G:
		for j in range(len(bp)-1,-1,-1):
			if bp[j] == 0:
				for _ in range(pd[j][0]):
					#print('here', j)
					total += (j+1)*100
					effort += 1
					if total >= G:
						break
				break
	ans.append([bp,total,effort])
#print(ans)

min_effort = float('INF')
for answer in ans:
	if answer[1]>=G:
		min_effort=min(min_effort, answer[2])

print(min_effort)
