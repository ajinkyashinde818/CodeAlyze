from collections import deque
s = input()
s = deque(s)
q = int(input())
reverse = False
for i in range(q):
    query = input()
    if len(query) == 1:
        reverse = not reverse
    else:
        if not reverse:
            if query[2] == '1':
                s.appendleft(query[4])
            else:
                s.append(query[4])
        else:
            if query[2] == '2':
                s.appendleft(query[4])
            else:
                s.append(query[4])
s ="".join(list(s))
if reverse:
    s = s[::-1]
print(s)
