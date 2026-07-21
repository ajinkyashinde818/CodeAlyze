from collections import deque
deq = deque(input())
rev = False
for _ in range(int(input())):
    query = input().split()
    if query[0] == '1':
        rev = not rev
    else:
        if (query[1] == '1') ^ rev:
            deq.appendleft(query[2])
        else:
            deq.append(query[2])
if rev:
    deq.reverse()
print(''.join(deq))
