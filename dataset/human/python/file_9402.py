N,K = map(int,input().split())
A = list(map(int,input().split()))
rd = [-1 for _ in range(N)]
rd[0] = 1

def nomal_loop():
    now_town = 1
    for _ in range(K):
        now_town = A[now_town-1]
    print(now_town)

    return 0

def else_loop():
    next_town = A[0]
    count = 1
    K_count = K
    while(1):
        count +=1
        K_count -= 1
        if rd[next_town-1] == -1:
            rd[next_town-1] = count
            next_town = A[next_town-1]
        else:
            warukazu = count - rd[next_town-1]
            result = (K_count+warukazu) % warukazu
            for _ in range(result):
                next_town = A[next_town-1]
            print(next_town)
            break
    return 0

if N > K:
    nomal_loop()
else:
    else_loop()
