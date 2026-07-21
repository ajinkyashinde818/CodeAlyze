import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())

ans = 0
if N%2==1:
    print(0)
    exit(0)
for i in range(1, 40):
    cnt = N//(5**i)
    ans += cnt//2
print(ans)
