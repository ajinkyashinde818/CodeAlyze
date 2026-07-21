from collections import deque

S = deque(list(input()))
Q = int(input())
l = []
for i in range(Q):
  l.append(list(input().split()))
    
flag = 1 #1ならふつう, -1なら逆


for i in range(Q):
    if l[i][0] == "1":
        flag *= -1
    elif flag == 1:
        if l[i][1] == "1":
            S.appendleft(l[i][2])
            
        else:
            S.append(l[i][2])
            
    else:
        if l[i][1] == "2":
            S.appendleft(l[i][2])
            
        else:
            S.append(l[i][2])


if flag == 1:
    print("".join(S))
else:
    S.reverse()
    print("".join(S))
