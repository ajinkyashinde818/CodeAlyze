import queue
from collections import defaultdict
import sys
sys.setrecursionlimit(10 ** 9)

def main():
    N,M = [int(x) for x in input().split()]
    C = defaultdict(list)
    for _ in range(M):
        a,b = [int(x) for x in input().split()]
        C[a-1].append(b-1)
    
    # bfs
    q = queue.Queue()
    # ステップ数
    V = [0]*N
    V[0] = 0
    # 始点
    s = 0
    while True:
        # print(s)
        for u in C[s]:
            # print(u,V[u])
            if V[u] == 0:
                q.put(u)
                V[u] = V[s]+1 # ステップ数
        if q.empty() or V[N-1] > 0:
            break
        s = q.get()
    # print(V[N-1])
    
    if 0 < V[N-1] and V[N-1] <= 2:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')
        
if __name__ == '__main__':
    main()
