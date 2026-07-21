from heapq import heappush, heappop
INF = 10**18
while 1:
    M, N, K, D = map(int, input().split())
    if M == N == K == D == 0:
        break
    *C, = map(int, input().split())
    def convert(s):
        if s == 'H':
            return 0
        if s[0] == 'C':
            return int(s[1:])
        if s[0] == 'L':
            return M+int(s[1:])
        return 1+N+M
    G = [[] for i in range(N+M+2)]
    H = [-1]*(N+M+2)
    for i in range(M):
        H[i+1] = i
    for i in range(D):
        s, t, e = input().split()
        s = convert(s); t = convert(t)
        e = int(e)
        G[s].append((t, e))
        G[t].append((s, e))

    dist = [[INF]*(1 << 6) for i in range(N+M+2)]
    que = [(0, 0, 0)]
    while que:
        cost, state, v = heappop(que)
        if dist[v][state] < cost:
            continue
        for w, e in G[v]:
            d = cost + e*K; n_state = state
            if H[w] != -1:
                if state & (1 << H[w]):
                    continue
                n_state |= (1 << H[w])
                d -= C[H[w]]
            if d < dist[w][n_state]:
                dist[w][n_state] = d
                heappush(que, (d, n_state, w))
    print(min(dist[N+M+1]))
