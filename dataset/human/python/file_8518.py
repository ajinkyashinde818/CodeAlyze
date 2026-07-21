def main():
    from builtins import int, map, list, print, min
    import sys
    sys.setrecursionlimit(10 ** 6)

    input = sys.stdin.readline
    input_list = (lambda: input().rstrip().split())
    input_number = (lambda: int(input()))
    input_number_list = (lambda: list(map(int, input_list())))

    K, N = input_number_list()
    A = input_number_list()
    A.sort()
    ans = A[-1] - A[0]
    for i in range(1, N - 1):
        l = A[i] + (K - A[i + 1])
        r = K - A[i] + A[i - 1]
        ans = min(ans, l, r)
    ans = min(ans, K - A[-1] + A[-2])
    print(ans)


if __name__ == '__main__':
    main()
