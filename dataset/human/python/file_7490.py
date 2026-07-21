from collections import deque
s = input()
s = deque(s)
q = int(input())

rev = 0
for i in range(q):
    inp = list(input().split())
    if inp[0] == '1':rev = rev^1
    else:
        if (inp[1] == '1' and rev == 0) or (inp[1] == '2' and rev == 1):
            s.appendleft(inp[2])
        else:
            s.append(inp[2])

s = list(s)
if rev == 1:s = s[::-1]
print(*s, sep = '')
