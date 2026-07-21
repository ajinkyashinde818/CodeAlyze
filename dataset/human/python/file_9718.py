def D():
    N, K = map(int, input().split())
    A = [int(i) for i in input().split()]
    town = 1
    visited = {}
    count = 0
    while town not in visited:
        visited[town] = count
        if count == K:  #ends before cycle ends
            print(town)
            return
        town = A[town-1]
        count += 1
    start_of_cycle = visited[town]
    end_of_cycle = count
    length_of_cycle = end_of_cycle - start_of_cycle
    to_go = (K - end_of_cycle)%length_of_cycle
    # print(start_of_cycle, end_of_cycle, length_of_cycle, to_go)
    for i in range(to_go):
        town = A[town-1]
    print(town)
D()
