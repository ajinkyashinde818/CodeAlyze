def main():
    n, m = list(map(int, input().split()))
    connect_1 = set()
    connect_n = set()
    for _ in range(m):
        a, b = list(map(int, input().split()))
        if a == 1:
            connect_1.add(b)
        elif b == n:
            connect_n.add(a)
        else:
            pass
    if connect_1.isdisjoint(connect_n):
        print('IMPOSSIBLE')
    else:
        print('POSSIBLE')

if __name__ == '__main__':
    main()
