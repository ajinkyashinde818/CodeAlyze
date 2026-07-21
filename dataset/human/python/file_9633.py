import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, K = mapint()
As = list(mapint())
doubling = [[0]*N for _ in range(61)]
doubling[0] = list(map(lambda x:x-1, As))

for i in range(1, 61):
    for j in range(N):
        doubling[i][j] = doubling[i-1][doubling[i-1][j]]

now = 0
for i in range(61):
    if (K>>i)&1:
        now = doubling[i][now]
print(now+1)
