from collections import deque

S = deque(list(input()))

ans = 0
while len(S) > 1:
    l = S.popleft()
    r = S.pop()
    if l == r:
        continue
    elif l == 'x':
        ans += 1
        S.append(r)
    elif r == 'x':
        ans += 1
        S.appendleft(l)
    else:
        print(-1)
        exit()
print(ans)
