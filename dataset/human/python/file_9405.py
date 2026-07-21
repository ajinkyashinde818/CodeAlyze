def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    cycle = 0
    flag = True
    visited = [0] * N
    visited[0] = 1
    visited_num = [0] * N
    before_city = 0
    visited_city = 0
    periodic = 0
    while flag:
        next_city = A[before_city] - 1
        cycle += 1
        if cycle >= K:
            flag = False
        if visited[next_city] == 1:
            visited_city = next_city
            periodic = cycle - visited_num[next_city]
            flag = False
        else:
            visited[next_city] = 1
            visited_num[next_city] = cycle
            before_city = next_city
    #print(periodic)
    #print(visited_city)
    if cycle < K:
        K_new = (K - cycle) % periodic
        before_city = visited_city
        for i in range(K_new):
            next_city = A[before_city] - 1
            before_city = next_city
        print(next_city+1)
    else:
        print(next_city+1)

if __name__ == '__main__':
    main()
