def q4():
    N, K = [int(i) for i in input().split(" ")]
    A = [-1] + [int(i) for i in input().split(" ")]

    arrived = []
    arrived_set = set()
    current = 1
    loop_start_station = -1
    while True:
        arrived.append(current)
        arrived_set.add(current)
        current = A[current]
        if current in arrived_set:
            loop_start_station = arrived.index(current)
            break

    if K <= loop_start_station:
        print(arrived[K])
        return
    K = K - loop_start_station
    arrived = arrived[loop_start_station:]
    K = K % len(arrived)
    print(arrived[K])
        

q4()
