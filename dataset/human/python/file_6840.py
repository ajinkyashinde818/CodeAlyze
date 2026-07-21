from collections import deque

L = deque([])
S = str(input())
q = int(input())
Q = [[] for _ in range(q)] 

for i in range(len(S)):
    L.append(S[i])

for i in range(q):
    A = input().split()
    Q[i] = A

num = 0

for i in range(q):
    if Q[i][0] == '1':
        num ^= 1
    if Q[i][0] == '2':
        if num == 0:
            if Q[i][1] == '1':
                L.appendleft(Q[i][2])
            else:
                L.append(Q[i][2])
        else:
            if Q[i][1] == '2':
                L.appendleft(Q[i][2])
            else:
                L.append(Q[i][2])

if num:
    L.reverse()

print(''.join(L))
