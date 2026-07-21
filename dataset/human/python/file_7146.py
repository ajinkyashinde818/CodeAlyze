from collections import deque

is_reverse = False
s = deque(input())
q = int(input())
for _ in range(q):
    query = input().split()
    if query[0] == '1':
        is_reverse = not is_reverse
    else:
        if (not is_reverse and query[1] == '1') or (is_reverse and query[1] == '2'):
            s.appendleft(query[2])
        else:
            s.append(query[2])
print(''.join(s)[::-1]) if is_reverse else print(''.join(s))
