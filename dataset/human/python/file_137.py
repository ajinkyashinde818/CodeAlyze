import sys, re

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
MOD = 10 ** 9 + 7


R, G, B, N = MAP()
count = 0
for i in range(N+1):
	for j in range(int((N-i*R)//G)+1):
		# print(r, g, b)
		# if R*i + G*j + B*int(max(0, (N - i*R - j*G))/B) == N:
		# 	count += 1
		if (N - i*R - j*G) % B == 0:
			count += 1
print(count)
