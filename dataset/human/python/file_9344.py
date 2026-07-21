import numpy as np

N, K = map(int, input().split())

A = np.array(list(map(int, input().split()))) - 1

roop = [-1]*N
is_visited = [-1]*N

roop[0] = 0
is_visited[0] = 0

for i in range(N-1):
    if is_visited[A[roop[i]]] >= 0:
        for idx, j in enumerate(roop):
            if j == A[roop[i]]:
                r = i+1-idx
                print(roop[idx + (K - idx) % r] + 1)
                exit()

    elif i == K:
        print(roop[i] + 1)
        exit()

    roop[i+1] =  A[roop[i]]
    is_visited[roop[i]] = i
