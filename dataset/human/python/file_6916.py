from collections import deque
queue = deque(input())
q = int(input())
li = [list(input().split()) for _ in range(q)]

flag = 1
for i in range(q):
    if int(li[i][0]) == 1:
        flag *= -1
        continue

    if int(li[i][1]) == 1:
        if flag == 1:
            queue.appendleft(li[i][2])
        else:
            queue.append(li[i][2])
    else:
        if flag == 1:
            queue.append(li[i][2])
        else:
            queue.appendleft(li[i][2])

if flag == 1:
    print("".join(queue))
else:
    ans = list(queue)
    print("".join(ans[::-1]))
