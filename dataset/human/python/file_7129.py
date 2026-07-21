import collections
S = collections.deque(list(input()))
Q=int(input())

q=[0]*Q
turn=0
houkou=['']*2
for i in range(Q):
    q[i]=input()

    if(q[i][0]=='1'):
        turn=not turn

    else:
        if(turn==0):
            if(q[i][2]=='1'):
                S.appendleft(q[i][4])

            else:
                S.append(q[i][4])
        else:
            if(q[i][2]=='1'):
                S.append(q[i][4])

            else:
                S.appendleft(q[i][4])



if(turn==0):
    print(''.join(S))
else:
    S.reverse()
    print(''.join(S))
