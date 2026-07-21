from collections import deque
s = input()
que = deque(list(s))
q = int(input())
flag = True
for _ in range(q):
    l = input()
    if flag:
        if l[0] == "1":
            flag = False
        else:
            if l[2] == "1":
                que.appendleft(l[4])
            else:
                que.append(l[4])
    else:
        if l[0] == "1":
            flag = True
        else:
            if l[2] == "1":
                que.append(l[4])
            else:
                que.appendleft(l[4])
if flag:
    ans = list(que)
    print("".join(ans))
else:
    ans = list(que)[::-1]
    print("".join(ans))
