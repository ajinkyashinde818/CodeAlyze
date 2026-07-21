def find_cycle_start(A, start=1):
    N = len(A)
    next_nodes = [a - 1 for a in A]
    start -= 1
    visited = [0 for _ in range(N)]
    node = start
    visited[node] = 1
    for _ in range(N):
        node = next_nodes[node]
        if visited[node] == 1:
            break
        visited[node] = 1
    return node + 1  # start of cycle


def main():
    N, K = list(map(int, input().split(' ')))
    A = list(map(int, input().split(' ')))
    cycle_start = find_cycle_start(A)
    offset = list()
    a = 1
    while True:
        a = A[a - 1]
        if a == cycle_start:
            break
        offset.append(a)
    cycle = [cycle_start]
    period = 0
    for _ in range(N):
        a = A[a - 1]
        period += 1
        if a == cycle_start:
            break
        cycle.append(a)
    # calculate answer
    if K <= len(offset):
        print(offset[K - 1])
    else:
        rest = K - len(offset)
        print(cycle[(rest - 1) % period])


if __name__ == '__main__':
    main()
