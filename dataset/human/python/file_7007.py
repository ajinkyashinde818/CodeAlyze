from collections import deque
S = input()
Q = int(input())
querys = [input() for _ in range(Q)]
is_reverse = False
d = deque([S])

for q in querys:
    query = q.split()
    if len(query) == 1:
        is_reverse = not is_reverse
        continue
    _, f, c = query
    if is_reverse:
        
        if f == "1":
            d.append(c)
        elif f == "2":
            d.appendleft(c)
    else:
        if f == "1":
            d.appendleft(c)
        elif f == "2":
            d.append(c)
if is_reverse:
    print("".join(d)[::-1])
else:
    print("".join(d))
