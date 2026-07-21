from collections import deque
s=input()
q=int(input())
flg=True
s1=deque()
s2=deque()
for _ in range(q):
    t=list(input().split())
    if t[0]=='1':
        flg=not flg
    else:
        if t[1]=='1':
            if flg:
                s1.appendleft(t[2])
            else:
                s2.append(t[2])
        else:
            if flg:
                s2.append(t[2])
            else:
                s1.appendleft(t[2])
if flg:
    print(''.join(s1)+s+''.join(s2))
else:
    print(''.join(s2)[::-1]+s[::-1]+''.join(s1)[::-1])
