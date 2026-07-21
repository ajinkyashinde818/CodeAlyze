import sys
from collections import deque
input = sys.stdin.readline

s = deque(input().strip())
q=int(input())
count = 0
for i in range(q):
    L = list(input().rstrip().split())    
    if L[0]=='1':
        count += 1
    else:
        a,b,c = L
        b = int(b)
        if count&1==1:
            b=3-b
        if b==2:
            s.append(c)
        else:
            s.appendleft(c)
if count&1==1:
    print("".join(list(s)[::-1])) 
else:
    print("".join(s))
