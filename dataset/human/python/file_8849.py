def main():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    answer = a[-1] - a[0]
    for i in range(n - 1):
        answer = min(answer, max(a[i + 1] - a[i], k + a[i] - a[i + 1]))
    print(answer)


if __name__ == '__main__':
    main()
