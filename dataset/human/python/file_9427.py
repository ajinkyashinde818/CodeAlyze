def main():
    N, K = map(int,input().split(' '))
    to = list(map(int,input().split(' ')))
    to.insert(0, 0)
    dist = [0] * (N+1) # 頭からの距離
    distance = 0
    node = 1 # start
    mod = 1
    for _ in range(N):
        node = to[node]
        K-=1
        distance += 1
        if K==0:
            print(node)
            exit(0)
        if node == 1:
            mod = distance
            break
        elif dist[node] == 0:
            dist[node] = distance
        else:
            mod = distance - dist[node]
            break
    K %= mod
    for _ in range(K):
        node = to[node]
    print(node)

    
if __name__ == "__main__":
    main()
