from collections import deque

s = deque(input())
q = int(input())
flip = 1
for i in range(q):
    T = input().split()
    if T[0] == '1':
        flip *= -1
    else:
        _flip = 1 if T[1]=='1' else -1
        if (flip * _flip)==1:
            s.appendleft(T[2])
        else:
            s.append(T[2])
print("".join(s) if flip==1 else "".join(reversed(s)))
