from collections import deque
s = deque(input())
q = int(input())
isRight = True
for i in range(q):
    query = input()
    if query[0] == '1':
        isRight = not(isRight)
    else:
        _, f, c = query.split()
        if f == '1':
            if isRight:
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if isRight:
                s.append(c)
            else:
                s.appendleft(c)
t = ''.join(list(s))
if not isRight:
    reversed(t)
print(t if isRight else t[::-1])
