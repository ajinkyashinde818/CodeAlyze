import sys
from collections import Counter
from collections import deque
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

n,m=mp()
x=[]
y=[]
for i in range(m):
    a,b=mp()
    if a==1:
        x.append(b)
    if b==n:
        y.append(a)
if len(list(set(x) & set(y)))>=1:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
