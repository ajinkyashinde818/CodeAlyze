from collections import deque
s = deque(list(input()))
q = int(input())
cnt = 0
for _ in range(q):
    fc = input().split()
    if fc[0] == '1':
        cnt += 1
    else:
        if cnt == 1:
            fc[1] = '1' if fc[1] == '2' else '2'
        if fc[1] == '1':
            s.appendleft(fc[2])
        else:
            s.append(fc[2])
    cnt %= 2
if cnt == 1:
    s.reverse()
print(*s, sep='')
