N, K = map(int, input().split())
A = list(map(int, input().split()))

def findLoop():
  dp = [0 for _ in range(N)]
  next = 0;
  count = 1;
  acc = []
  while dp[next]==0:
    dp[next] = count
    acc.append(next+1)
    count += 1
    next = A[next]-1
  freq = count - dp[next]
  return(acc[:dp[next]-1], acc[len(acc)-freq:])

first, loop = findLoop()

if K<max(0, len(first)-1):
  print(first[K])
else:
  print(loop[ ( K-len(first) ) % len(loop)])
