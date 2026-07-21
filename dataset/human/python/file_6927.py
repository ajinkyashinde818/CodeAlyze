from collections import deque
S= deque(input())
Q = int(input())
ba = 1
for i in range(Q):
    Query =list(map(str,input().split()))
    Query0 = Query[0]
    if Query[0] == '1':
        ba *= -1
    else:
        if Query[1] == '1' and ba ==1:
            S.appendleft(Query[2])
        elif Query[1] == '1' and ba ==-1:
            S.append(Query[2])
        elif Query[1] == '2' and ba ==1:
            S.append(Query[2])
        elif Query[1] == '2' and ba ==-1:
            S.appendleft(Query[2])
if ba == -1:
    S.reverse()
mojieru = ''.join(S)
print(mojieru)
