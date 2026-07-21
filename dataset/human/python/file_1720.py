import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, M = mapint()
As = [list(input()) for _ in range(N)]
Bs = [list(input()) for _ in range(M)]

def check(i, j):
    for h in range(M):
        for w in range(M):
            if As[i+h][j+w]!=Bs[h][w]:
                return False
    return True

for i in range(N-M+1):
    for j in range(N-M+1):
        if check(i, j):
            print('Yes')
            exit(0)
else:
    print('No')
