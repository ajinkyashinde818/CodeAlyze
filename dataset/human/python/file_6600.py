from collections import deque
s = input()
q = int(input())
ans = deque(s)
rev = 0
for i in range(q):
    qi = input()
    if qi[0] == '1':
        rev += 1
    else:
        if (int(qi[2]) + rev%2) % 2:
            ans.appendleft(qi[4])
        else:
            ans.append(qi[4])

if rev % 2:
    ans.reverse()
for i in ans:
    print(i, end='')
