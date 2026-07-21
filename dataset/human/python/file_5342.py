import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

from collections import deque 
def main():
    n, m = map(int, readline().split())
    to = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int, readline().split())
        a -= 1
        b -= 1
        to[a].append(b)
        to[b].append(a)

    INF = int(1e6) 
    dq = deque()
    dq.append(0)
    dist = [INF for _ in range(n)]
    dist[0] = 0
    while len(dq)>0: 
        v = dq.popleft()
        for nx in to[v]:
            if dist[nx] != INF:
                continue
            dq.append(nx)    
            dist[nx] = dist[v]+1
    if dist[n-1] == 2:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")
if __name__ == '__main__':
    main()
