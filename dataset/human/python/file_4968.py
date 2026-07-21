import sys
def I(): return int(sys.stdin.readline())
def LI(): return [int(x) for x in sys.stdin.readline().split()]

mod = 10**9+7

def main():
    N = I()
    X = LI()
    D = [X[-1]-x for x in X[:-1]]

    f = 1
    for i in range(1,N):
        f *= i
        f %= mod

    ans = 0
    for i in range(N-1):
        tmp = (D[i] * f)%mod
        tmp *= pow(i+1,mod-2,mod)
        tmp %= mod
        ans += tmp
        ans %= mod
    print(ans)



if __name__ == "__main__":
    main()
