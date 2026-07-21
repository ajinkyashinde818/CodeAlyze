from collections import deque

S = input()
Q = int(input())
q = deque(S)
fg = False
for i in range(Q):
    que = list(map(str , input().split()))
    if que[0] == "1":
        fg = not fg
    elif (que[1] == "1" and fg == False) or (que[1] == "2" and fg == True) :
        q.appendleft(que[2])
    else:
        q.append(que[2])
if fg:
    q.reverse()
print("".join(q))
