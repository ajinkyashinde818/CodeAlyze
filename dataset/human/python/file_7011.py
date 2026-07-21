import collections


def resolve():
    s = input()
    n = int(input())
    d = collections.deque()
    d.appendleft(s)

    rev = False
    for _ in range(n):
        q = list(input().split())

        if len(q) == 1:
            rev = not rev

        else:
            if q[1] == '1':
                las = False

            else:
                las = True

            if rev:
                las = not las

            if las:
                d.append(q[2])

            else:
                d.appendleft(q[2])

    dstr = ''.join(d)

    if rev:
        print(dstr[::-1])

    else:
        print(dstr)
        
resolve()
