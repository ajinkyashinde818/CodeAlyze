def main():
    n, m = map(int, input().split())
    Ton, Fr1 = set(), set()
    for _ in range(m):
        a, b = map(int, input().split())
        if b==n:
            Ton.add(a)
        if a==1:
            Fr1.add(b)

    print('POSSIBLE' if Ton&Fr1 else 'IMPOSSIBLE')

main()
