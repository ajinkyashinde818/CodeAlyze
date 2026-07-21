import sys
def input():
    return sys.stdin.readline()[:-1]


def main():
    N, K = map(int,input().split())
    A = list(map(int,input().split()))
    graph = []
    for i in range(N):
        graph.append(int(A[i] - 1))

    
    new = [True] * N
    num = 0
    visited = []
    while True:
        new[num] = False
        visited.append(num)
        num = graph[num]
        if not new[num]: #bool型なので
            visited.append(num)
            break
    v = visited.index(visited[-1])
    l = len(visited)
    kurikaeshi = l - v - 1
    if K + 1 <= l:
        print(visited[K] + 1)
    else:
        amari = (K + 1 - v) % kurikaeshi
        if amari == 0:
            amari = kurikaeshi
        print(visited[v + amari - 1] + 1)

    
if __name__ == "__main__":
    main()
