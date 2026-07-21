def main():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    a.append(a[0] + k)

    max_length = 0
    for i in range(n):
        max_length = max(max_length, a[i+1] - a[i])

    print(k - max_length)


if __name__ == '__main__':
    main()
