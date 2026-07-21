import sys
from itertools import accumulate
N = int(input())
S = input()
if S[0]=='W' or S[-1]=='W':
  print(0)
  sys.exit()
MOD = 10**9+7
p = 1
ls = [p]
for i in range(1,2*N):
  if S[i]==S[i-1]:
    p = (p+1)%2
    ls.append(p)
  else:
    ls.append(p)
if p!=0:
  print(0)
  sys.exit()
if ls.count(1)!=N:
  print(0)
  sys.exit()
A = list(accumulate(ls))
m = 0
ans = 1
for i in range(1,N+1):
  ans *= i
  ans %= MOD
for i in range(2*N):
  if ls[i]==0:
    ans *= A[i]-m
    ans %= MOD
    m += 1
print(ans)
