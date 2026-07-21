nums=[int(x) for x in input().split()]
V,E = nums[0],nums[1]
graph = {x:[] for x in range(V)}

for i in range(E):
    nums=[int(x) for x in input().split()]
    a,b = nums[0]-1,nums[1]-1
    graph[a].append(b)
    graph[b].append(a)


if __name__ == '__main__':
	goal = V - 1
	mids = graph[0]
	for isl in mids:
		if goal in graph[isl]:
			print("POSSIBLE")
			exit(0)
	print("IMPOSSIBLE")
