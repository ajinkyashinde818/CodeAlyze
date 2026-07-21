def main():
    N, M = map(int, input().split())
    adj = [set() for _ in range(N+1)]
    for _ in range(M):
        a, b = map(int, input().split())
        adj[a].add(b)
        adj[b].add(a)
    for i in range(2, N):
        if i in adj[1] and N in adj[i]:
            print("POSSIBLE")
            return
    print("IMPOSSIBLE")


if __name__ == "__main__":
    main()
