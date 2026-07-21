def main():
    N, K = map(int, input().split())
    A = [a-1 for a in list(map(int, input().split()))]
    visited = [0] * N
    bofore_loop_route = []
    route = []
    town = A[0]
    while True:
        if visited[town] == 0:
            visited[town] = 1
            route.append(town)
            town = A[town]
        else:
            before_loop = route.index(town)
            bofore_loop_route = route[:before_loop]
            route = route[before_loop:]
            break
    if K <= len(bofore_loop_route):
        print(bofore_loop_route[K-1] + 1)
    else:
        idx = ((K - before_loop) % len(route)) - 1
        print(route[idx] + 1)


if __name__ == '__main__':
    main()
