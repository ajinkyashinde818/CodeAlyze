from collections import deque

S=deque(input())
Q=int(input())

st=False#順方向

for _ in range(Q):
    query=input()
    if len(query)==1:
        st= not st
    else:
        _,F,C=query.split()
        F=int(F)
        if st==False:
            if F==1:
                S.appendleft(C)
            else:
                S.append(C)
        else:
            if F==1:
                S.append(C)
            else:
                S.appendleft(C)

if st==False:
    ans=S
else:
    ans=reversed(S)

ans="".join(list(ans))
print(ans)
