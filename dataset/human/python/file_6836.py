from collections import deque

Ss = input()
Q = int(input())

anss = deque(Ss)
isRev = False
for _ in range(Q):
    vs = input().split()
    if vs[0] == '1':
        isRev = not isRev
    else:
        F, C = vs[1], vs[2]
        if F == '1':
            if isRev:
                anss.append(C)
            else:
                anss.appendleft(C)
        else:
            if isRev:
                anss.appendleft(C)
            else:
                anss.append(C)

#print('anss:', anss)
#print('isRev:', isRev)
anss = ''.join(anss)
if isRev:
    anss = anss[::-1]

print(anss)
