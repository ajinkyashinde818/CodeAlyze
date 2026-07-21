import collections
import sys

S=collections.deque(input())
Q=int(input())

r=0
for _ in range(Q):
    fs=next(sys.stdin).split()
    T=int(fs[0])
    if T==1:
        r^=1
    else:
        F,C=int(fs[1])-1,fs[2]
        if F==r:
            S.appendleft(C)
        else:
            S.append(C)

ans=''.join(reversed(S) if r else S)
print(ans)
