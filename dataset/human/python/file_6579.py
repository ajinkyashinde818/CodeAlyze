from collections import deque

s = input()
q = int(input())

t = deque(s)
flg = False
for _ in range(q):
    query = input()
    if query[0] == "1":
        flg = not flg
    elif query[0] == "2":
        _, f, c = query.split()
        if f == "1":
            if flg:
                t.append(c)
            else:
                t.appendleft(c)
        elif f == "2":
            if flg:
                t.appendleft(c)
            else:
                t.append(c)
result = "".join(t)
if flg:
    result = result[::-1]
print(result)
