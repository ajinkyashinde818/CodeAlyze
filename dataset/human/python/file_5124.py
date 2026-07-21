import bisect


def main():
    N, M = list(map(int, input().split(' ')))
    from_1 = list()
    to_n = list()
    for _ in range(M):
        a, b = list(map(int, input().split(' ')))
        if a == 1:
            from_1.append(b)
        elif b == N:
            to_n.append(a)
    from_1.sort()
    for via in to_n:
        index = bisect.bisect_left(from_1, via)
        if index < len(from_1) and from_1[index] == via:
            print('POSSIBLE')
            return
    print('IMPOSSIBLE')


if __name__ == '__main__':
    main()
