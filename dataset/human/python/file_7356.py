def resolve():
    from collections import deque
    s = deque(input())
    q = int(input())
    qlist = [input().split() for i in range(q)]
    flip = False
    for j in range(q):
        if qlist[j][0] == "1":
            flip = not flip
        elif qlist[j][1] == "1":
            if flip:
                s.append(qlist[j][2])
            else:
                s.appendleft(qlist[j][2])
        elif qlist[j][1] == "2":
            if flip:
                s.appendleft(qlist[j][2])
            else:
                s.append(qlist[j][2])
    if not flip:
        print("".join(s))
    else:
        s.reverse()
        print("".join(s))
resolve()
