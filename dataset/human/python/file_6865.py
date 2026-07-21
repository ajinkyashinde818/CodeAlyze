def abc158d_string_formation():
    from collections import deque
    s = deque(list(input()))
    q = int(input())
    flip = 0
    for _ in range(q):
        query = list(input().split())
        if query[0] == '1':
            flip = 1-flip
        elif query[1] == '1':
            if flip == 0:
                s.appendleft(query[2])
            else:
                s.append(query[2])
        else:
            if flip == 0:
                s.append(query[2])
            else:
                s.appendleft(query[2])
    if flip == 1:
        s = ''.join(reversed(s))
    else:
        s = ''.join(s)
    print(s)
abc158d_string_formation()
