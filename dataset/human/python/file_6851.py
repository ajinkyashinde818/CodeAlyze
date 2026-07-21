from collections import deque
import copy

S = list(input())
Q = int(input())
Q_list = [input().split() for i in range(Q)]

sn = 0
s = 0

Ans_list1 = deque([])

for k in range(len(S)):
    Ans_list1.append(S[k])

for j in range(Q):
    if Q_list[j][0] == "1":
        s += 1

if s % 2 == 1:
    Ans_list1.reverse()

Ans_list2 = copy.deepcopy(Ans_list1)

for i in range(Q):
    if Q_list[i][0] == "1":
        sn += 1
    else:
        if (sn % 2 == 0 and Q_list[i][1] == "1") or (sn % 2 == 1 and Q_list[i][1] == "2"):
            Ans_list1.appendleft(Q_list[i][2])
            Ans_list2.append(Q_list[i][2])
        else:
            Ans_list1.append(Q_list[i][2])
            Ans_list2.appendleft(Q_list[i][2])


if sn % 2 == 0:
    print(''.join(Ans_list1))
else:
    print(''.join(Ans_list2))
