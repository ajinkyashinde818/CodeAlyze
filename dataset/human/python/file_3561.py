import numpy as np
from bisect import bisect_right
N = int(input())
U = 10**6
pls = np.zeros(U,np.int32)
pls[2] = 1
pls[3::2] = 1
for i in range(3,U,2):
  if pls[i]==1:
    pls[i*i::2*i] = 0
t = list(np.where(pls)[0])
dic = {}
ls = [i*(i-1)//2 for i in range(1,10**6)]
for p in t:
  cnt = 0
  while N%p==0:
    N //= p
    cnt += 1
  dic[p] = cnt
if N!=1:
  dic[N] = 1
ans = 0
for k in dic.keys():
  i = bisect_right(ls,dic[k])
  if i!=0:
    ans += i-1
print(ans)
