from collections import deque

N,M,*abf = map(int, open(0).read().split())
ab = [abf[i:i+2] for i in range(0, len(abf), 2)]

connected = [[]for _ in range(N+1)]
for u, v in ab:
    connected[u].append(v)
    connected[v].append(u)
    
d = deque([])
for x in connected[1]:
    if x == N:
        print('POSSIBLE')
        break
    else:
        d.append(x)
else:
    while d:
        temp = d.popleft()
        for x in connected[temp]:
            if x == N:
                print('POSSIBLE')
                break
        else:
            continue
        break
    else:
        print('IMPOSSIBLE')
