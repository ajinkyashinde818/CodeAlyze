import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    from collections import deque
    d=deque(input())
    q=int(input())
    rev=False
    for i in range(q):
        l=input().split()
        if len(l)==1:
            if rev:
                rev=False
            else:
                rev=True
        else:
            if rev:
                if l[1]=='1':
                    d.append(l[2])
                else:
                    d.appendleft(l[2])
            else:
                if l[1]=='1':
                    d.appendleft(l[2])
                else:
                    d.append(l[2])
    if rev:
        d=reversed(d)
    print(''.join(d))
resolve()
