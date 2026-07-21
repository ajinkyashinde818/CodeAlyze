def main():
    N = int(input())
    A = list(map(int, input().split(' ')))
    cumsum = A
    for i in range(1, N):
        cumsum[i] += cumsum[i - 1]
    ans = 10 ** 15
    for i in range(N - 1):
        ans = min([ans, abs(cumsum[i] - (cumsum[-1] - cumsum[i]))])
    print(ans)


if __name__ == '__main__':
    main()
