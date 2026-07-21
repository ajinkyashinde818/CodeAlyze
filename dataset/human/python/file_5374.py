def main():
    n, m = map(int, input().split())
    ss = [set(), set()]
    for _ in range(m):
        a, b = map(lambda s: int(s) - 1, input().split())
        if a == 0:
            ss[0].add(b)
        elif a == n - 1:
            ss[1].add(b)
        if b == 0:
            ss[0].add(a)
        elif b == n - 1:
            ss[1].add(a)
    if ss[0] & ss[1]:
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')


if __name__ == '__main__':
    main()
