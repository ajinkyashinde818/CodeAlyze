def main():
    N = int(input())
    S = input()
    mod = pow(10, 9) + 7
    d = dict()
    for c in S:
        d[c] = d.get(c, 0) + 1
    ans = 1
    for c in d:
        ans *= (d[c]+1)
        ans %= mod
    return (ans - 1) % mod


if __name__ == '__main__':
    print(main())
