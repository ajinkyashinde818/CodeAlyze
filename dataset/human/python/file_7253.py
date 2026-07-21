import sys
input = lambda: sys.stdin.readline().strip()
from collections import deque
s=deque(str(input()))
q=int(input())
flag=0
for i in range(q):
    j=input()
    if j[0]=="1":
        flag+=1
    else:
        if flag%2==1:
            if j[2]=="1":
                s.append(j[4])
            else:
                s.appendleft(j[4])
        else:
            if j[2]=="1":
                s.appendleft(j[4])
            else:
                s.append(j[4])
s=''.join(s)
if flag%2==1:
    s=s[::-1]
print(s)
