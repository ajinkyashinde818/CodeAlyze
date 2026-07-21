import sys
input = sys.stdin.buffer.readline
from math import hypot
from scipy.sparse.csgraph import dijkstra,csgraph_from_dense
import numpy as np

def main():
	sx, sy, gx, gy = map(int, input().split())
	n = int(input())
	v = [(sx, sy, 0), (gx, gy, 0)]
	for _ in range(n):
		v.append(tuple(map(int, input().split())))
	d = np.full((n + 2, n + 2), np.inf)
	for i, p1 in enumerate(v):
		for j, p2 in enumerate(v[i + 1:]):
			d[i][i + j + 1] = max(0, hypot(p1[0] - p2[0], p1[1] - p2[1]) - p1[2] - p2[2])
	print(dijkstra(csgraph_from_dense(d,null_value=np.inf),False,0)[1])

if __name__ == '__main__':
	main()
