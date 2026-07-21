from collections import deque
s = deque(input())
q = int(input())

cnt = 1
for i in range(q):
    t_f_c = list(input().split())
    if t_f_c[0] == "1":
        cnt *= -1
    elif t_f_c[0] == "2":
        if cnt == 1: #反転-
            if t_f_c[1] == "1":
                s.appendleft(t_f_c[2])
            elif t_f_c[1] == "2":
                s.append(t_f_c[2])
        elif cnt == -1:  #反転+
             if t_f_c[1] == "2":
                s.appendleft(t_f_c[2])
             elif t_f_c[1] == "1":
                s.append(t_f_c[2])
if cnt == 1:
    print("".join(s))
elif cnt == -1:
    s.reverse()
    print("".join(s))
