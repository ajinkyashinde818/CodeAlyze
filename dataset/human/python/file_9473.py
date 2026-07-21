def main():
    N, K = map(int, input().split())
    A = [int(a) for a in input().split()]
    visited = [False for i in range(N)]

    ind = 0
    cnt_toloop = 0
    for i in range(N):
        if visited[ind] == False:
            visited[ind] = True
            ind = A[ind] - 1
            cnt_toloop += 1
        else:
            break

    start = ind
    ind = start
    cnt = 0
    for i in range(N):
        if A[ind] - 1 == start:
            cnt += 1
            break
        else:
            ind = A[ind] - 1
            cnt += 1

    step = 0
    ind = 0
    
    if K >= cnt_toloop:
        K -= cnt_toloop
        K = K % cnt

        step = cnt_toloop + K

        for i in range(step):
                ind = A[ind] - 1
        print(ind + 1)
   
    else:
        step = K
        for i in range(step):
            ind = A[ind] - 1
        print(ind + 1)
    
if __name__ == "__main__":
    main()
