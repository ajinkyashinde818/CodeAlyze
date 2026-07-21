def main():
    n, k, s = map(int, input().split())
    ans = [str(s)] * k + [str(s + 1)] * (n - k) if s != 10 ** 9 else [str(s)] * k + ['1'] * (n - k)
    print(' '.join(ans))


if __name__ == '__main__':
    main()
