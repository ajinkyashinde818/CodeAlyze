def main():
    N, K, S = map(int, input().split())
    MaxN = 10 ** 9
    if S == MaxN:
        A = [S] * K + [1] * (N - K)
    else:
        A = [S] * K + [S + 1] * (N - K)

    print(" ".join(map(str, A)))


if __name__ == "__main__":
    main()
