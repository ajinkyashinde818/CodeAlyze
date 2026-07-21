from collections import deque

S = deque(input())
Q = int(input())

head = 1
for _ in range(Q):
    cmd = input()
    if cmd == "1":
        head *= -1
    elif "2 1" == cmd[:3]:
        if head == 1:
            S.appendleft(cmd[4])
        else:
            S.append(cmd[4])
    else:
        if head == 1:
            S.append(cmd[4])
        else:
            S.appendleft(cmd[4])

ans = ""
for _ in range(len(S)):
    if head == 1:
        ans += S.popleft()
    else:
        ans += S.pop()

print(ans)
