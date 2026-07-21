import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

K, N = mapint()
As = list(mapint())

lis = []
for i in range(1, N):
    lis.append(As[i]-As[i-1])
lis.append(As[0]+(K-As[-1]))
print(K-max(lis))
