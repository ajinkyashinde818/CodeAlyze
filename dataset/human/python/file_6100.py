def solve():
  n = int(input())
  a = list(int(i) for i in input().split())
  b = list(int(i) for i in input().split())
  c = list(int(i) for i in input().split())
  ans = 0
  preryouri = -3
  for i in range(n):
    ryouri = a[i]-1
    ans += b[ryouri]
    if ryouri-preryouri == 1:
      ans += c[preryouri]
    preryouri = ryouri
  print(ans)
solve()
