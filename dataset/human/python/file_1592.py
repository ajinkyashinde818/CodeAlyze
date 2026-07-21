def mask_judge(a, b, i, j):
    flag = 1
    for k in range(m):
        for l in range(m):
            if a[i+k][j+l] != b[k][l]:
                flag = 0
                break
    return flag


def main():
    a = [[0 if i == '.' else 1 for i in input()] for _ in range(n)]
    b = [[0 if i == '.' else 1 for i in input()] for _ in range(m)]

    flag = 0
    for i in range(n-m+1):
        for j in range(n-m+1):
            if mask_judge(a, b, i, j):
                flag = 1
                break
    if flag:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    n, m = map(int, input().split())
    main()
