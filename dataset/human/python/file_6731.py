from collections import deque

s = deque(input())
len_queries = int(input())
queries = [input().split() for _ in range(len_queries)]

is_forward = True
for query in queries:
    if "1" == query[0]:
        is_forward = not is_forward
    else:
        if is_forward:
            if "1" == query[1]:
                s.appendleft(query[2])
            else:
                s.append(query[2])
        else:
            if "1" == query[1]:
                s.append(query[2])
            else:
                s.appendleft(query[2])
if not is_forward:
    s.reverse()
print("".join(s))
