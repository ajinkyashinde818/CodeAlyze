import math
N, K, S = map(int,input().split())

if S % 2 == 1:
  big = math.ceil(S/2)
  small = math.floor(S/2)
else:
  big = int(S/2)
  small = big

ans = list()
if N == K:
  for i,j in enumerate(range(N)):
    ans.append(S)
elif S == 1:
  for i,j in enumerate(range(N)):
    if i < K:
      ans.append(1)
    else:
      ans.append(2)
else:
  for i,j in enumerate(range(N)):
    if i <= K:
      if i % 2 == 0:
        ans.append(small)
      else:
        ans.append(big)
    else:
      if S != 10**9:
        ans.append(S+1)
      else:
        ans.append(S-1)
print(" ".join(map(str,ans)))
