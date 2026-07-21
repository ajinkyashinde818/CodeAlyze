from collections import deque

s = input()
q = int(input())
ans = deque(s)
cnt = 0
for i in range(q):
    f = [i for i in input().split()]
    if f[0] == '1':
        cnt += 1
    else:
        if f[1] == '1':
            if cnt % 2 == 0:
                ans.appendleft(f[2])
            else:
                ans.append(f[2])
        else:
            if cnt % 2 == 0:
                ans.append(f[2])
            else:
                ans.appendleft(f[2])
if cnt % 2 != 0:
    ans.reverse()
print(''.join(map(str,ans)))
