from collections import deque

S = input()

ans = 0
Q = deque(S)
while len(Q) >= 2:
    left, right = Q[0], Q[-1]

    if left == right:
        Q.popleft()
        Q.pop()
    elif left == 'x':
        Q.popleft()
        ans += 1
    elif right == 'x':
        Q.pop()
        ans += 1
    else:
        print(-1)
        quit()

print(ans)
