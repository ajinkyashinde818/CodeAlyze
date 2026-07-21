import sys

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

same = 0
for i in range(n):
	if a[i] == b[i]:
		same += 1
	elif b[i]*2 >= a[i]:
		print(-1)
		sys.exit()

if same == n:
	print(0)
	sys.exit()

edges = [[] for _ in range(51)]
for i in range(1, 51):
	for j in range(1, i+1):
		edges[i].append([i%j, j])

available = [True for _ in range(51)]
visited = [False for _ in range(51)]

def dfs(start, goal, cur):
	global visited
	if cur == goal:
		return True
	for e, k in edges[cur]:
		if visited[e] == False and available[k] == True:
			visited[e] = True
			if dfs(start, goal, e) == True:
				return True
	return False

ans = 0
for k in range(50, 0, -1):
	available[k] = False
	ok = True
	for i in range(n):
		visited = [False for _ in range(51)]
		visited[a[i]] = True
		if dfs(a[i], b[i], a[i]) == False:
			ok = False
			break
	if not ok:
		ans += 2**k
		available[k] = True

print(ans)
