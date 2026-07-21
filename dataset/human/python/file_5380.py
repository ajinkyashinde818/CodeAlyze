def solve():
    N, M, *AB = map(int, open(0).read().split())
    FROM_1 = set()
    TO_N = set()
    for i in range(M):
        a, b = AB[2*i], AB[2*i + 1]
        if a == 1:
            FROM_1.add(b)
        elif a == N:
            TO_N.add(b)
        if b == 1:
            FROM_1.add(a)
        elif b == N:
            TO_N.add(a)
    ans = FROM_1 & TO_N
    print('POSSIBLE') if ans else print('IMPOSSIBLE')

if __name__ == '__main__':
   solve()
