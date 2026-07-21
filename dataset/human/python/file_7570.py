from collections import deque


s = list(input())
q = int(input())
ans = deque(s)
cnt = 0
for i in range(q):
    arr = list(map(str, input().split()))
    if arr[0] == '1':
        cnt += 1
        cnt %= 2
    else:
        if (arr[1] == '1' and cnt == 0) or (arr[1] == '2' and cnt == 1):
            ans.appendleft(arr[2])
        else:
            ans.append(arr[2])
if cnt == 0:
    print(*ans, sep='')
else:
    ans.reverse()
    print(*ans, sep='')
