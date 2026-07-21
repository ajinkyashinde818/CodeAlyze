def main():
    n, m = input().split()
    g1 = []
    g2 = []
    for _ in range(int(m)):
        x, y = input().split()
        if x == '1':
            g1.append(y)
        elif y == n:
            g2.append(x)
    sx = set(g1)
    sy = set(g2)
    sxy = sx.intersection(sy)
    if len(sxy):
        print('POSSIBLE')
    else:
        print('IMPOSSIBLE')

if __name__ == '__main__':
    main()
