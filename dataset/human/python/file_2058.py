mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline

    N = int(input())
    S = input().rstrip('\n')

    C = Counter(S)
    ans = 1
    for x in C.values():
        ans = (ans * (x+1))%mod
    print(ans-1)


if __name__ == '__main__':
    main()
