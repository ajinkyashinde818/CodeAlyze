import copy
from collections import deque
import sys
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
mod = 10**9 + 7
inf = float('inf')
ans = inf

D, G = LI()

P = [0]*D
c = [0]*D
p = [0]*D

for i in range(D):
    P[i], c[i] = LI()

full = [0]*D
for i in range(D):
    full[i] = 100*(i+1)*P[i] + c[i]

for i in range(2**D):
    ansC = int(0)
    p = copy.deepcopy(P)
    candi = [i for i in range(D)]
    cur = int(0)
    for j in range(D):
        if ((i >> j) & 1):
            cur += full[D-j-1]
            ansC += p[D-j-1]
            candi.remove(D-j-1)

    remain = G - cur
#    print(candi,remain,ansC)
    while(candi and remain>0):
        remain -= (candi[-1]+1)*100
        p[candi[-1]] -=1
#        print(p)
        ansC +=1
        if p[candi[-1]]==0:
            candi.remove(candi[-1])

    ans = min(ansC,ans)

print(ans)
