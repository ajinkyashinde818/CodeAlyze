from collections import deque
S = input()
Q = int(input())
li = []
for i in range(Q):
    li.append(list(input().split()))
flag = False
sq = deque(S)
for i in range(Q):
    if li[i][0] == "1":
        flag = not flag
    else:
        if (li[i][1] == "1" and not flag) or (li[i][1] == "2" and flag):
            sq.appendleft(li[i][2])
        else:
            sq.append(li[i][2])
sq = list(sq)
if flag:
    sq.reverse()
for i in range(len(sq)):
    print(sq[i], end="")
