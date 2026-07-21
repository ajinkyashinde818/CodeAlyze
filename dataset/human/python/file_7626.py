from collections import deque

S = list(input())
S = deque(S)
Q = int(input())
reverse = 1
query = [input().split() for i in range(Q)]
for i in query:
    if len(i) == 1:
        reverse *= -1
    elif (i[1]=='1' and reverse == 1) or (i[1]=='2' and reverse==-1):
        S.appendleft(i[2])
    else:
        S.append(i[2])
if reverse == -1:
   S.reverse() 
print(''.join(list(S)))
