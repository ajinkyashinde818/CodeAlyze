from collections import deque
S = deque(input())
Q = int(input())

a = 0
for i in range(Q):
    t = input()
    if t == "1":
        if a == 0:
            a = 1
        else:
            a = 0
    else:
        t,f,c = t.split()
        if f == "1":
            if a == 0:
                S.appendleft(c)
            else:
                S.append(c)
        else:
            if a == 0:
                S.append(c)
            else:
                S.appendleft(c)
            
if a == 1:
    S = reversed(S)
    
S = ''.join(S)
print(S)
