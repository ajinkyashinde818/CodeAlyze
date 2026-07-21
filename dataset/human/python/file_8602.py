def solution():
    k, n = map(int, input().split())
    house = list(map(int, input().split()))
    next_dist = []

    for i in range(1, len(house)):
        next_dist.append(house[i]-house[i-1])
    next_dist.append(k-house[len(house)-1]+house[0])
    max_dis_index = next_dist.index(max(next_dist))
    del next_dist[max_dis_index]
    print(sum(next_dist))

solution()
