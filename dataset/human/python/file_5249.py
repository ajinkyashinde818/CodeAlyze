def ABC068C():
    N, M = map(int, input().split())
    flag = [[False, False] for _ in range(N)]

    for _ in range(M):
        a, b = map(int, input().split())
        if a == 1:
            flag[b][0] = True
        elif b == N:
            flag[a][1] = True

    for i in range(N):
        if flag[i][0] and flag[i][1]:
            print('POSSIBLE')
            return

    print('IMPOSSIBLE')
    return

ABC068C()
