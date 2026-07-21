from collections import deque

S = input()
Q = int(input())
ans = deque(S)
cnt = 0
for i in range(Q):
    qlst = list(map(str, input().split()))
    if qlst[0] == '1':
        cnt += 1
        continue
    else:
        if qlst[1] == '1':
            if cnt % 2 == 0:
                ans.appendleft(qlst[2])
            else:
                ans.append(qlst[2])
        else:
            if cnt % 2 == 0:
                ans.append(qlst[2])
            else:
                ans.appendleft(qlst[2])

if cnt % 2 == 1:
    print(''.join(reversed(ans)))
else:
    print(''.join(ans))
