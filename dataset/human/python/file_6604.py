S = input()
Q = int(input())
Switch = False
Query = []

import collections
dq = collections.deque(S)

for i in range(Q):
    s = input()
    if s[0] == '1':
        if Switch:
            Switch = False
        else:
            Switch = True
    if s[0] == '2':
        if s[2] == '1' and Switch==False:
            dq.appendleft(s[4])
#             S = s[4]+S
        elif s[2]=='1' and Switch==True:
            dq.append(s[4])
#             S = S+s[4]
        elif s[2] == '2' and Switch==False:
            dq.append(s[4])
#             S = S+s[4]
        else:
#             S = s[4]+S
            dq.appendleft(s[4])

if Switch == False:
    print(''.join(dq))
else:
    print(''.join(dq)[::-1])
