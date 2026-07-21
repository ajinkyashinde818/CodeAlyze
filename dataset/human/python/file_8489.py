def main():
    k, n = map(int, input().split())
    a_lst = list(map(int, input().split()))

    d_lst = [0 for _ in range(n)]

    for i in range(n - 1):
        d_lst[i] = a_lst[i + 1] - a_lst[i]

    d_lst.append(a_lst[0] + k - a_lst[n - 1])

    ans = k - max(d_lst)

    print(ans)


if __name__ == "__main__":
    main()
