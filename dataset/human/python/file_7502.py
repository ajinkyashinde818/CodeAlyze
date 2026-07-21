from collections import deque

S = deque(input())
Q = int(input())
re_flag = False 
start = deque()
finish = deque()
for i in range(Q):
    l = input()
    if l == "1":
        re_flag = not bool(re_flag)
    else:
        t, f, c = l.split()
        if f == "1":
            if re_flag:
                finish.append(c)
            else:
                start.append(c)
        else:
            if re_flag:
                start.append(c)
            else:
                finish.append(c)

S.extend(finish)
S.extendleft(start)

ans = deque()
if re_flag:
    ans.extendleft(S)
else:
    ans = S

print("".join(list(ans)))
