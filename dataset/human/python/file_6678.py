from collections import deque
S = input()
q = deque()
for s in list(S):
    q.append(s)
Q = int(input())
direction = True
for _ in range(Q):
    line = input()
    if line[0] == '1':
        direction = not direction
    else:
        if (direction and line[2] == '1') or (not direction and line[2] == '2'):
            q.appendleft(line[4])
        else:
            q.append(line[4])
print("".join(q) if direction else "".join(reversed(q)))
