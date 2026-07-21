import sys
input = sys.stdin.readline

S=list(input()[:-1])
Q=int(input()[:-1])
f=0
back=[]
forward=[]

for _ in range(Q):
    q=input().split()
    if int(q[0])==1:
        f = (f+1)%2
    if int(q[0])==2:
        if int(q[1])==1:
            if f==0:
                forward.append(q[2])
            else:
                back.append(q[2])
        else:
            if f==0:
                back.append(q[2])
            else:
                forward.append(q[2])

if f==0:
    print("".join(forward[::-1]+S+back))
else:
    print("".join((forward[::-1]+S+back)[::-1]))
