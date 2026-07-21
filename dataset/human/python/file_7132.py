from collections import deque

s = deque(input())
q = int(input())
rev = 0 # revが0のとき先頭、1のとき後尾

for _ in range(q):
    t = input().split()

    if len(t) == 1:
        rev ^= 1
    else:
        if rev == 1:
            if t[1] == '1':
                s.append(t[2])
            else:
                s.appendleft(t[2])
        else:
            if t[1] == '1':
                s.appendleft(t[2])
            else:
                s.append(t[2])

if rev == 1:
    s.reverse()

print(''.join(s))
