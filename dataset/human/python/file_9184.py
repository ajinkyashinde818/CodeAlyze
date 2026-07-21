from collections import deque

S = list(input())
S.reverse()
l = len(S)

def rev(x):
    x = list(x)
    x.reverse()
    return x

a = list(map(rev,['dream','dreamer','erase','eraser']))
q = deque()
q.append(["",0])

while len(q):
    b,i = q.pop()
    if i == l:
        print('YES')
        exit()
    x = 0
    f = True
    for B in b:
        if i+x >= l or S[i+x] != B:
            f = False
        x += 1
    if f:
        for A in a:
            q.append([A,i+x])

print('NO')
