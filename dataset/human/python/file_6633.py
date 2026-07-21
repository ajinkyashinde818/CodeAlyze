from collections import deque

s = input()
q = int(input())
S = deque(s)
head = True

for i in range(q):
    li = input().split()
    if li[0] == '1':
        head = not head
    else:
        if head:
            if li[1] == '1':
                S.appendleft(li.pop())
            else:
                S.append(li.pop())
        else:
            if li[1] == '2':
                S.appendleft(li.pop())
            else:
                S.append(li.pop())
s = ''.join(S)
if not head:
    s = s[::-1]
print(s)
