printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

from collections import deque
ss = ins()
s = deque([ss[i] for i in range(len(ss))])
dir = 0
q = inn()
for qq in range(q):
    a = input().split()
    if a[0]=='1':
        dir = 1-dir
    else:
        f = a[1]
        c = a[2]
        if f=='1' and dir==0 or f=='2' and dir==1:
            s.appendleft(c)
        else:
            s.append(c)
    #ddprint(f"s {s} dir {dir}")
if dir==1:
    s.reverse()
print(''.join(s))
