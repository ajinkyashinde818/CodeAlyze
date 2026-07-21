from collections import deque
s = list(input())
q_num = int(input())

s_deq = deque(s)
reversed = False

for _ in range(q_num):
    query = input().split()
    if query[0] == '1':
        reversed = False if reversed else True
    elif query[0] == '2':
        if not reversed:
            if query[1] == '1':
                s_deq.appendleft(query[2])
            elif query[1] == '2':
                s_deq.append(query[2])
        else:
            if query[1] == '2':
                s_deq.appendleft(query[2])
            elif query[1] == '1':
                s_deq.append(query[2])
if reversed:
    s_deq.reverse()
print(''.join(s_deq))
