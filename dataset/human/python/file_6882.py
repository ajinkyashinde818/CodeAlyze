from collections import deque

S = input()
Q = int(input())

lr = 'left'

def reverse_list(lr):
    if lr == 'right':
        return 'left'
    else:
        return 'right'

def moji_tuika(S, f, c, lr):
    if f == 1 and lr == 'left':
        S.appendleft(c)
    elif f == 1 and lr == 'right':
        S.append(c)
    elif f == 2 and lr == 'left':
        S.append(c)
    else:
        S.appendleft(c)
    return S

q = []
for i in range(Q):
    temp = input().split()
    if len(temp) == 1:
        q.append(1)
    else:
        q.append(temp)

S = deque(list(S))
for i in q:

    if type(i) == int:
        lr = reverse_list(lr)
    elif int(i[0]) == 2:
        S = moji_tuika(S,int(i[1]),i[2],lr)
if lr == 'right':
    S.reverse()

S = ''.join(S)
print(S)
