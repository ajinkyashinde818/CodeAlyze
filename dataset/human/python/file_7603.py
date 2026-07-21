from collections import deque
S = list(input())
Q = int(input())
que = [list(map(str, input().split())) for _ in range(Q)]

sq = deque(S)
cnt = 0

for i, lst in enumerate(que):
    if lst[0]=='1':
        cnt += 1
        continue
    if cnt%2==1:
        if lst[1]=='1':sq.append(lst[2])
        else:sq.appendleft(lst[2])
    else:
        if lst[1]=='1':sq.appendleft(lst[2])
        else:sq.append(lst[2])

ans = list(sq)
if cnt%2==1:
    ans.reverse()
print(''.join(ans))
