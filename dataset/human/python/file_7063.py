from collections import deque

def rev(s):
    new_s = list(reversed(s))
    return new_s

S = deque(input())
N = int(input())
r_flag=False
for _ in range(N):
    Q = input()
    if Q.isdigit():
        r_flag=not r_flag
    else:
        q = Q.split()
        if r_flag:
            if q[1]=="1":
                S.append(q[2])
            else:
                S.appendleft(q[2])
        else:
            if q[1]=="1":
                S.appendleft(q[2])
            else:
                S.append(q[2])
if r_flag:
    print(''.join(reversed(S)))
else:print(''.join(S))
