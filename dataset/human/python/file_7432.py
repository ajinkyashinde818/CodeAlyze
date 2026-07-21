from collections import deque

s = deque(input())
q = int(input())
reversed_flag = False

for i in range(q):
    query = input()
    if query == "1":
        reversed_flag = not reversed_flag
    else:
        t, f, c = query.split()
        if f == "1":
            if reversed_flag:
                s.append(c)
            else:
                s.appendleft(c)
        else:
            if reversed_flag:
                s.appendleft(c)
            else:
                s.append(c)

if reversed_flag:
    s.reverse()

print("".join(s))
