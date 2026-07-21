from collections import deque

s = input()

que = deque(s)
ans = 0
while que.__len__() > 1:
    if que[0] == que[-1]:
        que.popleft()
        que.pop()
    elif que[0] == 'x' and que[-1] != 'x':
        que.append('x')
        ans += 1
    elif que[0] != 'x' and que[-1] == 'x':
        que.appendleft('x')
        ans += 1
    else:
        print(-1)
        exit()
print(ans)
