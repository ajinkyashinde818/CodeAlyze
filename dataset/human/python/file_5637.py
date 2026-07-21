from collections import deque
s = list(input())
s = deque(s)
cnt = 0
while len(s) > 1:
    left = s.popleft()
    right = s.pop()
    if left == right:continue
    if left != 'x' and right != 'x':
        print(-1)
        exit()

    if left == 'x':
        s.append(right)
    else:
        s.appendleft(left)
    cnt += 1
print(cnt)
