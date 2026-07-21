import sys
N, M = map(int, input().split())
route = [[] for i in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    route[a-1].append(b)
    
for i in route[0]:
    if len(route) != 1:
        for j in route[i-1]:
            if j == N:
                print('POSSIBLE')
                sys.exit()
    else:
        if i == N:
            print('POSSIBLE')
            sys.exit()
                
print('IMPOSSIBLE')
