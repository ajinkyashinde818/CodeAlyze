from collections import deque
s = deque(input())

ans = 0
while s:
    top = s[0]
    end = s[-1]
    if top != end:
        if not (top == "x" or end == "x"):
            print(-1)
            break
        else:
            if top == "x":
                s.popleft()
            else:
                s.pop()
            ans += 1
    else:
        s.popleft()
        if s:
            s.pop()
else:
    print(ans)
