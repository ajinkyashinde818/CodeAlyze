from collections import deque

S = list(input())
Q = int(input())
d = deque(S)
reverse_flg = False

for i in range(Q):
    try:
        x, f, c = input().split()
        f = int(f)
        if f == 1 and not reverse_flg:
            d.appendleft(c)
        elif f == 1 and reverse_flg:
            d.append(c)
        elif f == 2 and not reverse_flg:
            d.append(c)
        else:
            d.appendleft(c)
    except:
        reverse_flg = not reverse_flg

if reverse_flg:
    d.reverse()

print("".join(d))
