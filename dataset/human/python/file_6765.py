from collections import deque

s = deque(input())
q = int(input())

reverse_flag = 1

for _ in range(q):
    query = input().split()
    if query[0] == "1":
        reverse_flag *= -1
    else:
        if (query[1] == "1" and reverse_flag == 1) or (query[1] == "2" and reverse_flag == -1):
            s.appendleft(query[2])
        else:
            s.append(query[2])
if reverse_flag == 1:
    print("".join(s))
else:
    s.reverse()
    print("".join(s))
