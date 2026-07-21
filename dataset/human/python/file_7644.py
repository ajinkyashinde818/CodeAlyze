from collections import deque

s=list(input())
s=deque(s)
q=int(input())

re=False
for i in range(1,q+1):
    q_i=input().split()
    if q_i[0]=="1":
        re= not re
    else:
        if q_i[1]=="1" and re==False:
            s.appendleft(q_i[2])
        elif q_i[1]=="2" and re==True:
            s.appendleft(q_i[2])
        else:
            s.append(q_i[2])

s=list(s)

if re==True:
    s=s[::-1]

s="".join(s)
print(s)
