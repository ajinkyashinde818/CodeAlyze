from collections import deque
s = deque(list(input()))
q = int(input())

reverse_flag = 1

for i in range(q):
    query = input().split()
    if query[0] == "1":
        reverse_flag *= -1
    else:
        if query[1] == "1":
            if reverse_flag == 1:
                s.appendleft(query[2])
            else:
                s.append(query[2])
        else:
            if reverse_flag == 1:
                s.append(query[2])
            else:
                s.appendleft(query[2])


if reverse_flag == -1:
    s.reverse()

print("".join(s))
