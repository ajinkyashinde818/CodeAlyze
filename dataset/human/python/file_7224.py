from collections import deque
s=deque(input())
q=int(input())
turn=True
 
for i in range(q):
    qq=input().split()
    if qq[0]=='1':
        turn=not turn
    else:
        if turn==bool(int(qq[1])-2):
            s.appendleft(qq[2])
        else:
            s.append(qq[2])
 

text="".join(s)
print(text if turn else text[::-1])
