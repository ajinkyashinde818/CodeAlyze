import sys
from collections import deque
def input(): return sys.stdin.readline().rstrip()
S = deque(input())
rev = False
apdlft = S.appendleft
apd = S.append

for _ in range(int(input())):
    q = input().split()
    if q[0] == '1':
        rev = not(rev)
    else:
        if (q[1]=='1' and rev is False) or (q[1]=='2' and rev is True):
            apdlft(q[2])
        else:
            apd(q[2])

if rev:
    print((''.join(S))[::-1])
else:
    print(''.join(S))
