from collections import deque
s = input()
queue = deque(list(s))
q = int(input())
pre = 0
reverse = 0
for _ in range(q):
    query = input()
    if query == '1':
        if pre:
            pre = 0
        else:
            pre = 1
        reverse += 1
    else:
        _, f, c = query.split()
        if f == '1':
            if pre == 0:
                # s = c + s
                queue.appendleft(c)
            else:
                # s = s + c
                queue.append(c)
        else:
            if pre == 1:
                # s = c + s
                queue.appendleft(c)
            else:
                # s = s + c
                queue.append(c)
if reverse % 2 == 1:
    queue = reversed(queue)
print(''.join(queue))
