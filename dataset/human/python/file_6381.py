import sys
MAX_INT = int(10e12)
MIN_INT = -MAX_INT
mod = 1000000007
sys.setrecursionlimit(1000000)
def IL(): return list(map(int,input().split()))
def SL(): return input().split()
def I(): return int(sys.stdin.readline())
def S(): return input()

N = I()
ans = 0

if N%2 == 0:
  N //= 2
  for i in range(1,100):
    ans += N//(5**i)
print(ans)
