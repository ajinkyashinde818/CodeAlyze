from collections import deque

s = input().strip()
s = deque(list(s))
q = int(input())

queries = [input().strip().split() for _ in range(q)]
is_reversed = False

for query in queries:
    t = query[0]
    if t == '1':
        is_reversed = not is_reversed
    else:
        f = query[1]
        c = query[2]
        if f == '1':
            if is_reversed:
                s.append(c)
            else:
                s.appendleft(c)
        else:
            if is_reversed:
                s.appendleft(c)
            else:
                s.append(c)

str_list = list(s)
if is_reversed:
    str_list = reversed(str_list)

ans = ''.join(str_list)
print(ans)
