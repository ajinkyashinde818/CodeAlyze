import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N, R = mapint()
if N>=10:
    print(R)
else:
    print(R+100*(10-N))
