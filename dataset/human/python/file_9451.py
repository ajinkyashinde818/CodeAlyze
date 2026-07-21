N, K = map(int, input().split())
A = list(map(int, input().split()))

def solve():
    visited = [-1]*N
    visited[0] = 0
    goto = 1
    counter = 0
    period = 0
    while 1:
        counter += 1 #counter 回ワープした
        goto = A[goto-1] #counter回目につく場所

        if counter == K:
            print(goto)
            return 0

        if visited[goto-1] == -1:
            visited[goto-1] = counter
        else:
            period = counter - visited[goto-1]
            break

    
    warp = 0
    here = 1
    while here != goto:
        warp += 1
        here = A[here-1]

    peri_and_rem = K - warp
    rem = peri_and_rem % period

    while rem > 0:
        rem -= 1
        here = A[here - 1]


    print(here)
    return 0
        



solve()
