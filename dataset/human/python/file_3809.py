import sys
input = sys.stdin.readline
sys.setrecursionlimit(2 * 10**6)


def inpl():
    return list(map(int, input().split()))


def divide(N):
    ret = {}
    p = 2
    tn = int(N**0.5)
    while N != 1:
        if N % p == 0:
            if p not in ret:
                ret[p] = 1
            else:
                ret[p] += 1
            N //= p
        elif p > tn:
            p = N
        else:
            p += 1

    return ret


def solve(N):
    p_dict = divide(N)
    ans = 0
    for v in p_dict.values():
        ans += int(((1 + 8 * v)**0.5 - 1) * 0.5)
    return ans


def main():

    N = int(input())
    print(solve(N))

    return


if __name__ == '__main__':
    main()
