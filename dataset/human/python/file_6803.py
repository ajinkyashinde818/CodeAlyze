import sys
from collections import deque

sys.setrecursionlimit(10**7)
input = sys.stdin.readline

s = input().rstrip()
q = int(input())
d = deque()
d.append(s)

flag = False
for i in range(q):
    qq = input().split()
    if qq[0] == '1':
        flag = not(flag)
    else:
        if flag:
            if qq[1] == '1':
                d.append(qq[2])
            else:
                d.appendleft(qq[2])
        else:
            if qq[1] == '1':
                d.appendleft(qq[2])
            else:
                d.append(qq[2])

ans = ''.join(list(d))
if flag:
    print(ans[::-1])
else:
    print(ans)
