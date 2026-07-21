import sys, math
from functools import lru_cache
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
    R, G, B, N = mi()
    cnt = 0

    for r in range(N//R+1):
        for g in range(N//G+1):
            bB = (N-R*r-G*g)
            if bB%B==0 and 0 <= bB:
                cnt += 1

    print(cnt)


if __name__ == '__main__':
    main()
