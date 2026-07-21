from collections import deque
S=input()
deque_S=deque(S)
flag=0
ans=0
while True:
    if len(deque_S)<=1:
        break
    if deque_S[0] == deque_S[-1]:
        deque_S.pop()
        deque_S.popleft()
    else:
        if deque_S[0] == 'x':
            ans+=1
            deque_S.popleft()
        elif deque_S[-1] == 'x':
            ans+=1
            deque_S.pop()
        else:
            flag=1
            break
if flag==1:
    print(-1)
else:
    print(ans)
