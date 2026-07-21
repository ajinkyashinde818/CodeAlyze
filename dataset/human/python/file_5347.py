import collections
def main():
    N, M = map(int, input().split())
    graph = collections.defaultdict(list)
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    cur = [1]
    visited = set([1])
    for _ in range(2):
        temp = []
        for i in cur:
            for j in graph[i]:
                if j not in visited:
                    temp.append(j)
                    visited.add(j)
        cur = temp
    if N in cur:
        return "POSSIBLE"
    return "IMPOSSIBLE"
if __name__ == '__main__':
    print(main())
