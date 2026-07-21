import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, log2
from itertools import accumulate, permutations, combinations, product, groupby
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from bisect import bisect, bisect_left
from fractions import gcd
from heapq import heappush, heappop
from functools import reduce
import numpy as np
def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
def ZIP(n): return zip(*(MAP() for _ in range(n)))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7
 
D, G = MAP()
pc = [LIST() for _ in range(D)]

count_min = 1001

for i in range(1<<D):
	count = 0
	sum = 0
	i = list("{:b}".format(i).zfill(D))
	#print(i)
	for j in range(D):
		if i[j] == "1":
			count += pc[j][0]
			sum += pc[j][0]*100*(j+1) + pc[j][1]

	if sum >= G:
		if count < count_min:
			#print("更新", count_min, ">", count)
			count_min = count

	else:
		for j in range(D-1, -1, -1):
			if i[j] == "0":
				remain_count = -(-(G-sum)//(100*(j+1)))
				#print(remain_count)
				if remain_count >= pc[j][0]:
					count = 1001
					break
				else:
					count += remain_count

				if count < count_min:
					#print("更新", count_min, ">", count)
					count_min = count

print(count_min)
