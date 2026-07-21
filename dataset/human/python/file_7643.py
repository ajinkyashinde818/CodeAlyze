from collections import deque
s = list(input())
queue = deque(s)

q = int(input())
rev_count = 0
for i in range(q):
    query = list(input().split(" "))
    if len(query) == 1:
        rev_count += 1
    else:
        if query[1] == "1":
            if rev_count % 2==0:
                queue.appendleft(query[2])
            else:
                queue.append(query[2])
        else:
            if rev_count % 2==0:
                queue.append(query[2])
            else:
                queue.appendleft(query[2])

queue = "".join(list(queue))
if rev_count % 2 == 0:
    print(queue)
else:
    print(queue[::-1])
