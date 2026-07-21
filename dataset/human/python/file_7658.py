import copy
from collections import deque
s = deque(input())
sc = copy.deepcopy(s) 
sc.reverse()
n = int(input())
l = [list(input().split()) for i in range(n)]

for i in range(n):
    if l[i][0] == '1':
        save = s
        s = sc
        sc = save
    elif l[i][1] == '1':
        s.appendleft(l[i][2])
        sc.append(l[i][2])
        #s = l[i][2] + s
        #sc += l[i][2]
    else:
        s.append(l[i][2])
        sc.appendleft(l[i][2])
        #s += l[i][2]
        #sc = l[i][2] + sc

print(''.join(s))
