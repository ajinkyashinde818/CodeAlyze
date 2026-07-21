def solve():
  import sys
  import math

  sys.setrecursionlimit(10**7)
  readline=sys.stdin.readline

  n = int(input())
  *a, = map(int,input().split())
  *b, = map(int,input().split())
  *c, = map(int,input().split())
  
  ans = sum(b)
  for i in range(1,n):
    if a[i]-a[i-1]==1:
      ans += c[a[i-1]-1]

  print(ans)


if __name__ == '__main__':
  solve()
