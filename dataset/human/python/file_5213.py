from collections import deque

N, M = map(int, input().split())
route = []
for i in range(M):
    route.append(list(map(int,input().split())))

island_map = {}
for a,b in route:
    if a not in island_map:
        island_map[a] = [b]
    else:
        island_map[a].append(b)

first_island = deque()
first_island += island_map[1]
second_island = deque()

for i in first_island:
    if i in island_map:
        second_island += island_map[i]
    else:
        pass
    for j in second_island:
        if j == N:
            print('POSSIBLE')
            exit()

print('IMPOSSIBLE')
