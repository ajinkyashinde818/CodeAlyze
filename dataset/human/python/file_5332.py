import sys
sys.setrecursionlimit(10**6)
if sys.platform in (['ios','darwin','win32']):
	sys.stdin=open('Untitled.txt')
input = sys.stdin.readline
def INT(): return int(input())
def MAP(): return [int(s) for s in input().split()]

N, M = MAP()
A = [MAP() for _ in range(M)]

A.sort(reverse=True)

B = [0] * N
B[0] = 1

for a in A:
	f = a[0]-1
	t = a[1]-1
	if f == 0:
		B[t] = 1

for a in A:
	f = a[0]-1
	t = a[1]-1
	if B[f] == 1:
		B[t] = 2

#print(B)
print("POSSIBLE" if B[-1] else "IMPOSSIBLE")
