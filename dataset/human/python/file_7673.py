from collections import deque

S = list(input())
Q = int(input())
Query = []
cnt_re = 0
for i in range(Q):
    tmp = input().split()
    Query.append(tmp)
    if (len(tmp) == 1):
        cnt_re += 1
prev = deque()
after = deque()
if (cnt_re % 2 != 0):
    S = list(reversed(S))
for q in Query:
    if (len(q) == 3):
        if q[1] == '1':
            if (cnt_re % 2 == 0):
                prev.appendleft(q[2])
            else:
                after.append(q[2])
        else:
            if (cnt_re % 2 == 0):
                after.append(q[2])
            else:
                prev.appendleft(q[2])
    else:
        cnt_re -= 1
print(''.join(list(prev)) + ''.join(list(S)) + ''.join(list(after)))
