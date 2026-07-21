from collections import deque

s = deque(input())
q = int(input())
is_reversed = False
for i in range(q):
    query = input().split()
    if query[0] == '1':
        is_reversed = not is_reversed
    elif (query[1] == '2') ^ is_reversed:
        s.append(query[2])
    else:
        s.appendleft(query[2])
if is_reversed:
    s.reverse()
print(''.join(s))
