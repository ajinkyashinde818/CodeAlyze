from collections import deque

s = input()
s_list = deque(list(s))

x_count = 0
flag = True
while len(s_list) > 1:

    s_head = s_list.popleft()
    s_tail = s_list.pop()

    if s_head == s_tail:
        continue
    elif s_head == "x":
        x_count += 1
        s_list.append(s_tail)
        continue
    elif s_tail == "x":
        x_count += 1
        s_list.appendleft(s_head)
        continue
    else:
        flag = False
        break

if flag:
    print(x_count)
else:
    print(-1)
