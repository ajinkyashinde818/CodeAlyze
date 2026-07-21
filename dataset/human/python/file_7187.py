from collections import deque

S = input()
Q = int(input())

S_list = list(S)

r = 1
a = []
b = []
d = deque(a)

for i in range(Q):
    q = input().split()
    if q[0] == '1':
        r *= -1
        continue
    elif len(q) == 3:
        if q[1] == '1':
            if r == -1:
                b.append(q[2])
            else:
                d.appendleft(q[2])
        else:
            if r == -1:
                d.appendleft(q[2])
            else:
                b.append(q[2])
                
answer = list(d) + S_list + b

if r == -1:
    answer = answer[::-1]
    
print(''.join(answer))
