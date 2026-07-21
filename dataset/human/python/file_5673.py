from collections import deque

s = input()

s = deque(s)

ans = 0
while len(s) > 0:
    if s[0] == s[-1]:
        if len(s) == 1:
            s.popleft()
        else:
            s.popleft()
            s.pop()

    elif s[0] == "x":
        s.popleft()
        ans += 1
    elif s[-1] == "x":
        s.pop()
        ans += 1
    else:
        print(-1)
        exit(0)

print(ans)
