from collections import deque
s = input()
n = int(input())
q = deque()

for i in range(len(s)):
    q.append(s[i])

flag = True
for i in range(n):
    query = input()
    if query[0]=="1":
        flag = not flag
    else:
        if query [2]=="1":
            if flag:
                q.appendleft(query[4])
            else:
                q.append(query[4])
        else:
            if flag:
                q.append(query[4])
            else:
                q.appendleft(query[4])
if flag:
    print(''.join(q))
else:
    q.reverse()
    print("".join(q))
