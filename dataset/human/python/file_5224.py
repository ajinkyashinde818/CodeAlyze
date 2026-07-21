N, M = [int(s) for s in input().split()]

def main():
    n = N
    s = []
    g = []
    for m in range(M):
        a, b = [int(s) for s in input().split()]
        if a == 1:
            s.append(b)
        if b == n:
            g.append(a)
    ans = 'POSSIBLE' if len(set(s) & set(g)) > 0 else 'IMPOSSIBLE'
    print(ans)

if __name__ == '__main__':
    main()
