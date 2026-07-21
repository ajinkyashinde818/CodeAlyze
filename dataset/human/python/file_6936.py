from collections import deque

s=input()
S=[]
for i in range(len(s)):
    S.append(s[i])
S=deque(S)
q=int(input())
flag=False
for i in range(q):
    t=input()
    if t=='1':
        if flag:
            flag=False
        else:
            flag=True
    else:
        if t[2]=='1':
            if flag:
                S.append(t[4])
            else:
                S.appendleft(t[4])
        elif t[2]=='2':
            if flag:
                S.appendleft(t[4])
            else:
                S.append(t[4])

if flag:
    x=''.join(S)
    print(x[::-1])
else:
    print(''.join(S))
