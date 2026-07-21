from collections import deque

S = input()
Q = int(input())
query = [input().split() for _ in range(Q)]

ans = deque(list(S))
flag = 0

for q in range(Q):
    if len(query[q]) == 1:
        flag = 1 - flag
    else:
        if query[q][1] == '1':
            if flag:
                ans.append(query[q][2])
            else:
                ans.appendleft(query[q][2])
        else:
            if not flag:
                ans.append(query[q][2])
            else:
                ans.appendleft(query[q][2])

if not flag:
    print(''.join(ans))
else:
    print(''.join(ans)[::-1])
