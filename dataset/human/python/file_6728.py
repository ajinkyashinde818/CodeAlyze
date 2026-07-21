from collections import deque
S = deque([input()])
Q=int(input())
query=[[i for i in input().split()] for _ in range(Q)]

rf=0
for q in query:
    if q[0] == "1":
        rf ^= 1
    else:
        if q[1] == '1':
            if rf:
                S.append(q[2])
            else:
                S.appendleft(q[2])
        else:
            if rf:
                S.appendleft(q[2])
            else: 
                S.append(q[2])
print(''.join(S)[::-1] if rf else ''.join(S))
