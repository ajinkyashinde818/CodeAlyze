from collections import deque

s = input()
q = int(input())
ls = [input().split() for _ in range(q)]

ans = deque(s)
cnt = 0

for t in ls:
    if t[0] == '1':
        cnt += 1
    elif t[0] == '2':
        if cnt % 2 == 0:
            if t[1] == '1':
                ans.appendleft(t[2])
            elif t[1] == '2':
                ans.append(t[2])
        elif cnt % 2 == 1:
            if t[1] == '1':
                ans.append(t[2])
            elif t[1] == '2':
                ans.appendleft(t[2])

if cnt % 2 == 0:
    print("".join(ans))
elif cnt % 2 == 1:
    ans.reverse()
    print("".join(ans))
