from collections import deque
S=deque(input())
Q=int(input())
ref=0
for i in range(Q):
    T=input().split()
    if T[0] == '2':
        if (T[1]=='1' and ref%2==0):
            S.appendleft(T[2])
        elif (T[1]=='2' and ref%2==0):
            S.append(T[2])
        elif (T[1]=='1' and ref%2==1):
            S.append(T[2])
        elif (T[1]=='2' and ref%2==1):
            S.appendleft(T[2])
    else:
        ref+=1
for i in range(len(S)):
    if ref%2==0:
        char=S.popleft()
        print(char,end='')
    else:
        char=S.pop()
        print(char,end='')
