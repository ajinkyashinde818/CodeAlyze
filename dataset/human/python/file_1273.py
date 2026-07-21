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
    a = list(mi())
    x = 0
    y = sum(a)
    m = 10**100
    for i in range(N-1):
        x += a[i]
        y -= a[i]
        m = min(m, abs(x-y))
    print(m)


if __name__ == '__main__':
    main()
