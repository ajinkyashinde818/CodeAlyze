def main():
    K, N = map(int, input().split())
    AN = list(map(int, input().split()))

    max_diff = 0
    for i in range(N - 1):
        max_diff = max(max_diff, AN[i + 1] - AN[i])
    max_diff = max(max_diff, AN[0] + K - AN[-1])

    print(K - max_diff)


main()
