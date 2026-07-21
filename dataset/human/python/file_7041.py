from collections import deque

s = deque(input())
q = int(input())
cnt = 0

for _ in range(q):
    qs = input().split()
    if qs[0] == '1':
        cnt += 1
    else:
        if qs[1] == '1':
            if cnt%2 == 0:
                s.appendleft(qs[2])
            else:
                s.append(qs[2])
        else:
            if cnt%2 == 0:
                s.append(qs[2])
            else:
                s.appendleft(qs[2])
ans = ''.join(s)
print(ans if cnt%2 == 0 else ans[::-1])
