from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)
n , k = map(int , input().split())
arr = list(map(int , input().split()))
dic = defaultdict(int)
for i in range(1,n+1):
	dic[i] = arr[i-1]
cycle = []
visited = [False]*(10**6)
curr = 1
while True:
	cycle.append(curr)
	visited[curr] = True
	curr = dic[curr]
	#k -= 1
	if visited[curr]:
		break

csize = 0
ind = 0
for i in range(len(cycle)-1,-1,-1):
	if cycle[i] == curr:
		ind = i + 1
		break
	csize += 1
offset = len(cycle) - csize - 1
#print(cycle,csize+1, k , curr,offset)
if k - offset < 0:
	exit(print(cycle[k]))
k -= offset
k %= csize + 1
print(cycle[offset + k])
