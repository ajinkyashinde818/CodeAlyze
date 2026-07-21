from collections import deque
S = deque(input())
Q = int(input())
cnt = 1
num = 0
for i in range(Q):
    TFC = input()
    if TFC == "1":
        cnt *= -1
        num += 1
    else:
        if TFC[:3]== "2 1":
            if cnt ==1:
                S.appendleft(TFC[4])
            else:
                S.append(TFC[4])
        else:
            if cnt ==1:
                S.append(TFC[4])
            else:
                S.appendleft(TFC[4])
if num % 2 ==1:
    print(("".join(reversed([i for i in S]))))
else:
    print(("".join([i for i in S])))
