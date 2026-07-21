import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

R, G, B, N = mapint()

ans = 0
for r in range(N//R+1):
    for g in range(N//G+1):
        rg = r*R + g*G
        if rg>N:
            continue
        if (N-rg)%B==0:
            ans += 1
print(ans)
