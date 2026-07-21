from collections import deque
que = deque()
ans = ''
s = list(input())
for i in range(len(s)):
    que.append(s[i])
q = int(input())
flag = 0# if head->0 elif tail ->1
for i in range(q):
    a = list(map(str, input().split()))
    if a[0] == '1':
        if flag == 0:
            flag =1
        else:
            flag = 0
    elif a[0] == '2':
        if a[1] == '1':
            if flag == 0:
                que.appendleft(str(a[2]))
            else:
                que.append(str(a[2]))
        elif a[1] == '2':
            if flag == 1:
                que.appendleft(str(a[2]))
            else:
                que.append(str(a[2]))
if flag == 0:
    for i in range(len(que)):
        ans += str(que.popleft())
elif flag == 1:
    for i in range(len(que)):
        ans += str(que.pop())
print(ans)
