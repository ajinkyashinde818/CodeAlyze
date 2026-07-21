from collections import defaultdict

n, m = [int(i) for i in input().split()]

graph = defaultdict(list)

for _ in range(m):
    a, b = [int(i) for i in input().split()]
    graph[a].append(b)
    graph[b].append(a)

for hop in graph[1]:
    for goal in graph[hop]:
        if goal == n:
            print("POSSIBLE")
            quit()
        else:
            continue

print("IMPOSSIBLE")
