def solve():
  raw = input().split()
  K = int(raw[0])
  N = int(raw[1])
  vals = [None] * N
  ans = 99999999
  raw = input().split()
  for i in range(N):
    vals[i] = int(raw[i])
  for i in range(N):
    cc = -1
    if i == 0:
      cc = vals[N-1] - vals[0]
    else:
      cc = vals[i-1] + K - vals[i]
    ans = min(ans, cc)
  print(ans)
solve()
