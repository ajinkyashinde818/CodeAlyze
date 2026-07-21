def main():
    n = int(input())
    a_lst = list(map(int, input().split()))
    b_lst = list(map(int, input().split()))
    c_lst = list(map(int, input().split()))
    ans = 0

    for a in a_lst:
        ans += b_lst[a - 1]

    for i in range(n - 1):
        if a_lst[i] + 1 == a_lst[i + 1]:
            ans += c_lst[a_lst[i] - 1]

    print(ans)


if __name__ == "__main__":
    main()
