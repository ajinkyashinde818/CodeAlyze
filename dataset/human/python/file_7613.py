import sys
read=sys.stdin.buffer.read
readline=sys.stdin.buffer.readline
readlines=sys.stdin.buffer.readlines
from collections import deque

S=deque(readline().rstrip().decode())
Q=int(readline())
query=readlines()

flag=False
for q in query:
    if q[0]==ord('1'):
        flag= not flag
    else:
        _,f,c=q.decode().split()
        f=int(f)
        if flag^(f==1):
            S.appendleft(c)
        else:
            S.append(c)
ans=''.join(S)
if flag:
    ans=ans[::-1]
print(ans)
