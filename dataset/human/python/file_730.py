import sys
from collections import deque, defaultdict
import copy
import bisect
sys.setrecursionlimit(10 ** 9)
import math
import heapq
from itertools import product, permutations,combinations
import fractions
from operator import itemgetter

import sys
def input():
	return sys.stdin.readline().strip()

xs, ys, xt, yt = list(map(int, input().split()))
N = int(input())
circle = [(xs, ys, 0)]
for i in range(N):
	circle.append(tuple(map(int, input().split())))
circle.append((xt, yt, 0))

graph = [[0]*(N + 2) for _ in range(N + 2)]

for i in range(N + 2):
	for j in range(i):
		dist = ((circle[i][0] - circle[j][0])**2 + (circle[i][1] - circle[j][1])**2)**0.5 - circle[i][2] - circle[j][2]
		dist = max(0, dist)
		graph[i][j] = dist
		graph[j][i] = dist

dist = [10**13]*(N + 2)
dist[0] = 0

node_list = []
heapq.heappush(node_list, (0, 0))
while len(node_list) > 0:
	node = heapq.heappop(node_list)
	if dist[node[1]] == node[0]:
		for i in range(N + 2):
			if i != node[1] and dist[i] > node[0] + graph[node[1]][i]:
				dist[i] = node[0] + graph[node[1]][i]
				heapq.heappush(node_list, (dist[i], i))

print(dist[-1])
