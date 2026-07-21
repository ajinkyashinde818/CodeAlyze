import sys
sys.setrecursionlimit(10**6)
if sys.platform in (['ios','darwin','win32']):
	sys.stdin=open('Untitled.txt')
input = sys.stdin.readline
def INT(): return int(input())
def MAP(): return [int(s) for s in input().split()]

N = INT()
A = MAP()
B = MAP()
C = MAP()

ans = 0
for idx,a in enumerate(A):
	ans += B[a-1]
	if idx < len(A)-1 and A[idx+1] == a+1:
		ans += C[a-1]

print(ans)
