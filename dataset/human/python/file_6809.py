S = input()
Q = int(input())
count = 0
from collections import deque
q1 = deque()
q2 = deque()
for i in range(Q):
    li = input().split()
    if len(li) == 1:
        count +=1
        q11 = q1
        q22 = q2
        q1 = q22
        q2 = q11
    if len(li) == 3:
        if li[1] == '1':
            if count % 2 == 1:
                q1.append(li[2])
            if count % 2 == 0:
                q1.appendleft(li[2])
        if li[1] == '2':
            if count % 2 == 1:
                q2.appendleft(li[2])
            if count % 2 == 0:
                q2.append(li[2])
s1 = ''.join(list(q1))
s2 = ''.join(list(q2))
if count % 2 == 1:
    K = reversed(list(S))
    S = ''.join(K)
    s1 = ''.join(reversed(list(s1)))
    s2 = ''.join(reversed(list(s2)))
print(s1+S+s2)
