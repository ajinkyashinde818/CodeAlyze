from collections import deque
def BFS(N,M,List):
    Graph = [[] for T in range(N+1)]
    for NodeM in range(0,M):
        Graph[List[NodeM][0]].append(List[NodeM][1])
        Graph[List[NodeM][1]].append(List[NodeM][0])

    Distance = [-1]*(N+1)
    Distance[0] = 0
    Distance[1] = 0
    From = [0]*(N+1)

    Deque = deque()
    Deque.append(1)
    while Deque:
        V = Deque.popleft()
        for NodeV in Graph[V]:
            if Distance[NodeV]==-1:
                Distance[NodeV] = Distance[V]+1
                Deque.append(NodeV)
                From[NodeV] = V

    return Distance[1:],From[1:]
  
N,M = (int(X) for X in input().split())
List = [[] for T in range(0,M)]
for T in range(0,M):
    List[T] = [int(X) for X in input().split()]
Distance,From = BFS(N,M,List)
if Distance[-1]==2:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
