from collections import deque

s = deque(input())
ans = 0
while s:
    L = s[0]
    R = s[-1]
    if L == R:
        if 1 == len(s):
            break
        L = s.popleft()
        R = s.pop()
        continue
    elif L == 'x' and R != 'x':
        ans += 1
        s.append('x')
    elif L != 'x' and R == 'x':
        ans += 1
        s.appendleft('x')
    elif L != 'x' and R != 'x':
        ans = -1
        break
print(ans)
