from collections import deque


N, M = map(int, input().split())
to = [[] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    a, b = a - 1, b - 1
    to[a].append(b)
    to[b].append(a)
    

def main():
    dist = [-1] * N
    dist[0] = 0
    que = deque([0])
    
    while que:
        v = que.popleft()
        for nv in to[v]:
            if dist[nv] == -1:
                dist[nv] = dist[v] + 1
                que.append(nv)
                
    print('POSSIBLE' if dist[N - 1] == 2 else 'IMPOSSIBLE')
    
    
if __name__ == '__main__':
    main()
