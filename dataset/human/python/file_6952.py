from collections import deque
import sys
input = sys.stdin.readline

S = deque(input().rstrip())
Q = int(input())
lst = deque()
 
for i in range(Q):
    tmp = list(input().split())
    lst.append(tmp)

reverse = 0
c = 1
for i in range(Q):
 
    if int(lst[i][0]) == 1:
        reverse += 1
        c += 1
    
    if int(lst[i][0]) == 2:
        if c%2 == 1:
            if int(lst[i][1]) == 1:
                S.appendleft(lst[i][2])
            else:
                S.append(lst[i][2])
        else:
            if int(lst[i][1]) == 2:
                S.appendleft(lst[i][2])
            else:
                S.append(lst[i][2])
 
if reverse%2 == 1:
    S.reverse()
 
ans = "".join(S)
print(ans)
