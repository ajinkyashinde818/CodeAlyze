import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

K, S = mapint()
cnt = 0
for i in range(K+1):
    for j in range(K+1):
        if 0<=(S-i-j)<=K:
            cnt += 1

print(cnt)
