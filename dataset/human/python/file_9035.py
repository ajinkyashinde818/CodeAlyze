from collections import deque

w = ["dream", "erase", "dreamer", "eraser"]
s = deque(list(input()))
c = 1
while s:
    u = deque()
    p = s.pop()
    u.append(p)
    if p == "r":
        for _ in range(5):
            u.appendleft(s.pop())
            if len(s) == 0:
                break
        if "".join(u) != w[3] and len(s) != 0:
            u.appendleft(s.pop())
            if "".join(u) != w[2]:
                c = 0
    else:
        for _ in range(4):
            u.appendleft(s.pop())
            if len(s) == 0:
                break
        if not "".join(u) in w:
            c = 0
    if c == 0:
        break
print("YES" if c == 1 else "NO")
