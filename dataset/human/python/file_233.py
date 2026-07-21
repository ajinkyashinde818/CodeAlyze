def main():
    n = int(input())

    c = 1
    while c * c <= 8 * n + 1:
        if c * c == 8 * n + 1:
            break
        c += 1
    else:
        print("No")
        exit()

    k, cnt = (c+1) // 2, 1
    ans = [set() for i in range(k)]
    for i in range(k):
        for j in range(i+1, k):
            ans[i].add(cnt)
            ans[j].add(cnt)
            cnt += 1

    print("Yes")
    print(k)
    for i in range(k):
        print(len(ans[i]), end=" ")
        for j in ans[i]:
            print(j, end=" ")
        print()


if __name__ == '__main__':
    main()
