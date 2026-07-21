import sys
input = sys.stdin.readline


def main():
    N, M = map(int, input().split())
    from_one = set([])
    to_n = set([])
    for _ in range(M):
        a, b = map(int, input().split())
        if a == 1:
            from_one.add(b)
        elif b == N:
            to_n.add(a)
    if len(from_one & to_n) > 0:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')


if __name__ == '__main__':
    main()
