def solve():
    K, S = map(int, input().split())
    
    lower = S - 2 * K
    if lower < 0:
        lower = 0
    
    cnt = 0
    for x in range(lower, K + 1):
        lower = S - K - x
        if lower < 0:
            lower = 0
        upper = S - x
        if upper > K:
            upper = K
        for y in range(lower, upper + 1):
            cnt += 1
    
    print(cnt)

solve()
