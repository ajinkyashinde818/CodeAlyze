from collections import deque
s = input()
n = int(input())
q_list = [input().split() for _ in range(n)]
d = deque(list(s))
r_flag = False
for q in q_list:
    if q[0] == "1":
        r_flag = not r_flag
    elif q[0] == "2":
        if q[1] == "1":
            if r_flag:
                d.append(q[2])
            else:
                d.appendleft(q[2])
        elif q[1] == "2":
            if r_flag:
                d.appendleft(q[2])
            else:
                d.append(q[2])
if r_flag:
    d.reverse()
print("".join(d))
