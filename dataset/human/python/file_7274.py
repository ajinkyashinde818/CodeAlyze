import sys
fastinput = sys.stdin.readline
from collections import deque
S = input()
Q = int(input())
ans = deque([S])
Reverse = False
for q in range(Q):
    query = fastinput().split()
    if query[0]=="1":
        Reverse = not Reverse
    elif (query[1]=="1") ^ Reverse:#左側にくっつく
        ans.appendleft(query[2])
    else:
        ans.append(query[2])
SS = "".join(list(ans))
if Reverse:
    SS = "".join(reversed(SS))
print(SS)
