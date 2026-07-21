from collections import deque

head = deque()
tail = deque()
count_rev = 0
switch = 0

S = input()
Q = int(input())

for i in range(Q):
    q = input()
    if(q == '1'):
        count_rev += 1
        if(switch == 1):
            switch = 0
        else:
            switch = 1

    else:
        tmp, f, c = q.split()
        if(f == '1'):
            # put head
            if(switch == 0):
                head.appendleft(c)
            else:
                tail.append(c)
        else:
            # put tail
            if(switch == 0):
                tail.append(c)
            else:
                head.appendleft(c)

reversed(head)
if(count_rev % 2 == 0):
    ans = list(head) + list(S) + list(tail)
else:
    s = list(S)
    s.reverse()
    ans = list(reversed(tail)) + s + list(reversed(head))

print(''.join(ans))
