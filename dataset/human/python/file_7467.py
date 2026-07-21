from collections import deque
S = deque(input())
Q = int(input())
s = 1
for _ in range(Q):
    q = input()
    if q!='1':
        if (q[2]=='1' and s==1) or (q[2]!='1' and s!=1):
            S.extendleft(q[4])
        else:
            S.extend(q[4])
    else:
        s *= -1
S = ''.join(list(S))
if s==1:
    print(S)
else:
    print(S[::-1])
