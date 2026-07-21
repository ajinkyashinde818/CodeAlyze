from queue import Queue
n, m = map(int, input().split())
adj = [[] for i in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
def bfs():
    queue = Queue()
    queue.put(1)
    distance = [10**6]*(n+1)
    distance[1] = 0
    while not queue.empty():
        u = queue.get()
        if u == n and distance[u] == 2:
            print ("POSSIBLE")
            return
        for a in adj[u]:
            if distance[u] + 1 <= 2 and distance[a] > distance[u] + 1:
                distance[a] = distance[u] + 1
                queue.put(a)
    print ("IMPOSSIBLE")
    return
bfs()
