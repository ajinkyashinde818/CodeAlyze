def main():
    N, K = map(int, input().split())
    A = list(map(lambda x: int(x)-1, input().split()))

    visited = [0] * N
    way = []
    now = 0

    while True:
        if visited[now] == 1: break
        if K == 0: return print(now+1)
        visited[now] = 1
        way.append(now)
        destination = A[now]
        K -= 1
        now = destination

    loop = way[way.index(now):len(way)]
    # print(loop)
    # print(K)
    print(loop[K%len(loop)]+1)



if __name__ == '__main__':
    main()
