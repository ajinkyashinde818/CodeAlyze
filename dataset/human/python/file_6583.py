from collections import deque
s = input()
q = int(input())
op = [input().split() for _ in range(q)]


flag = True
ans = deque(s)

for i in op:
    if i[0] == "1":
        flag = not flag
    else:
        if i[1] == "1":
            if flag:
                ans.appendleft(i[2])
            else:
                ans.append(i[2])
        else:
            if flag:
                ans.append(i[2])
            else:
                ans.appendleft(i[2])

if flag:
    while(ans):
        t = ans.popleft()
        print(t, end='')
else:
    while(ans):
        t = ans.pop()
        print(t, end='')
