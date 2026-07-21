def main():
    N, K = (int(_) for _ in input().split())
    A = [int(_)-1 for _ in input().split()]
    visited = [-1] * N
    now = cc = 0
    while True:
        if visited[now] == -1:
            visited[now] = cc
            cc += 1
            now = A[now]
        else:
            T = cc - visited[now]
            break
    if K < visited[now]:
        for i in range(N):
            if visited[i] == K:
                print(i+1)
                break
    else:
        K -= visited[now]
        for i in range(N):
            if visited[i] == K%T + visited[now]:
                print(i+1)
                break
    return


if __name__ == '__main__':
    main()
