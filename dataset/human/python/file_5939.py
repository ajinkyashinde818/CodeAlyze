import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())
As = list(mapint())
Bs = list(mapint())
Cs = list(mapint())
ans = 0

before = -2
for a in As:
    a -= 1
    ans += Bs[a]
    if a==before+1:
        ans += Cs[before]
    before = a
print(ans)
