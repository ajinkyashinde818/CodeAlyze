from collections import deque

reverse = False

S = deque(list(input()))

N = int(input())

for _ in range(N):
    cmd = input()
    if cmd[0] == '1':
        reverse = not reverse
    else:
        cmd = cmd.split()
        if cmd[1] == '1':
            if reverse:
                S.append(cmd[2])
            else:
                S.appendleft(cmd[2])
        else:
            if reverse:
                S.appendleft(cmd[2])
            else:
                S.append(cmd[2])

if reverse:
    S.reverse()

print(''.join(S))
