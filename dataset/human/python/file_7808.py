import sys
read = sys.stdin.read
readlines = sys.stdin.readlines
def main():
    """
    sum[Al,,,Ar] = Sの部分和がちょうどK個。
    """
    n, k, s = map(int, input().split())
    if n == k:
        r = [s] * k
    else:
        if s == 1000000000:
            r = [1000000000] * k + [1] * (n - k)
        else:
            r = [s] * k + [1000000000] * (n - k)

    print(*r, sep=' ')

if __name__ == '__main__':
    main()
