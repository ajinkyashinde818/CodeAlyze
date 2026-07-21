def main():
    import sys
    def input():
        return sys.stdin.readline()[:-1]

    N = int(input())
    S = input()

    if S[0]!='B' or S[-1]!='B':
        print(0)
        exit()

    mod = 10**9 + 7
    cnt = 1
    pre = 'B'
    d = 1 #1がleft
    ans = 1

    for i in range(1,N*2):
        if S[i-1]==S[i]:
            if d:
                d = 0
                ans *= cnt
                ans %= mod
                cnt -= 1
            else:
                d = 1
                cnt += 1
        else:
            if d:
                cnt += 1
            else:
                ans *= cnt
                ans %= mod
                cnt -= 1

    for i in range(1,N+1):
        ans *= i
        ans %= mod
    if cnt!=0:
        print(0)
        exit()

    print(ans)

if __name__=='__main__':
    main()
