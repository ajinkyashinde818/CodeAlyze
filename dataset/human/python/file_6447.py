import sys
sys.setrecursionlimit(500000)
MOD = 10**9+7

def input():
    return sys.stdin.readline()[:-1]

def mi():
    return map(int, input().split())

def ii():
    return int(input())

def i2(n):
    tmp = [list(mi()) for i in range(n)]
    return [list(i) for i in zip(*tmp)]

def main():
    N = ii()
    if N%2:
        print(0)
    else:
        m = N//2
        ans = 0
        t = 5
        while m >= t:
            ans += m//t
            t *= 5
        print(ans)


if __name__ == '__main__':
    main()
