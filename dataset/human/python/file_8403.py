import heapq
def main():
    k,n = map(int,input().split())
    a_n = map(int,input().split())
    l_1 = []
    l_2 = []
    for a_i in a_n:
        heapq.heappush(l_1,a_i)
        heapq.heappush(l_2,a_i)
    a_1 = heapq.heappop(l_2)
    heapq.heappush(l_2,a_1 + k)
    dif_m = 0
    for _ in range(n):
        start = heapq.heappop(l_1)
        goal = heapq.heappop(l_2)
        dif = goal - start
        if dif_m < dif:
            dif_m = dif
    print(k - dif_m)
                


if __name__ == "__main__":
    main()
