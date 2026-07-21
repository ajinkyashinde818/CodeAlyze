def solve():
    MOD = 10**9 + 7

    N = int(input())
    Ss = input()

    N2 = 2*N
    LRs = [0] * N2
    numL = 0
    for i, S in enumerate(Ss):
        if numL == 0:
            if S == 'W':
                return 0
            LRs[i] = 'L'
            numL += 1
        else:
            if S == 'W':
                if numL % 2:
                    LRs[i] = 'L'
                    numL += 1
                else:
                    LRs[i] = 'R'
                    numL -= 1
            else:
                if numL % 2:
                    LRs[i] = 'R'
                    numL -= 1
                else:
                    LRs[i] = 'L'
                    numL += 1
#    print(LRs)

    ans = 1
    numL = 0
    for LR in LRs:
        if LR == 'L':
            numL += 1
        else:
            if numL <= 0:
                return 0
            ans *= numL
            ans %= MOD
            numL -= 1
#    print(ans)

    if numL != 0:
        return 0

    fact = 1
    for i in range(1, N+1):
        fact = (fact*i) % MOD

    return ans*fact%MOD


ans = solve()
print(ans)
