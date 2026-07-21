def solve():
    R, G, B, N = [int(_) for _ in raw_input().split()]
    X = min(R, G, B)
    if X == R:
        Y = min(G,B)
        Z = max(G,B)
    elif X == G:
        Y = min(R,B)
        Z = max(R,B)
    else:
        Y = min(R,G)
        Z = max(R,G)
    ret = 0
    for i in range(N/Z, -1, -1):
        for j in range((N - i * Z)/Y, -1, -1):
            sum2 = N - i * Z - j * Y
            if sum2 % X == 0:
                ret += 1
    print str(ret)

if __name__ == '__main__':
    solve()
