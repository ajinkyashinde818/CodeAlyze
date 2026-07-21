import itertools
from collections import defaultdict
import collections
import sys
sys.setrecursionlimit(200000)
mod = 1000000007

n, k = map(int, input().split())
a = list(map(int, input().split()))

tf = [False] * (n + 1)
tf[1] = True
ss = [1]
cnt = 0
while cnt < max(k,n ** 2):
    if len(ss) != 1 and tf[a[ss[cnt] - 1]]:
        d = a[ss[cnt] - 1]
        break
    tf[a[ss[cnt] - 1]] = True
    ss.append(a[ss[cnt] - 1])
    cnt += 1

if len(ss) > k:
    print(ss[k])
else:
    sss = ss.index(d)
    print(ss[sss+(k -len(ss)) % (len(ss) - sss)])
    # print(ss.index(d))
    # print(ss[k % (len(ss) - ss.index(d))])
