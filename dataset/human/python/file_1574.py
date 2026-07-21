import sys
def main():
    n, m = map(int, input().split())
    A = [list(input()) for _ in range(n)]
    B = [list(input()) for _ in range(m)]

    for i in range(n - m + 1):
        for j in range(n - m + 1):
            f = 1
            for k in range(m):
                for l in range(m):
                    if A[i + k][j + l] != B[k][l]:
                        f = 0
                        break
                if f == 0:
                    break
            if f:
                print("Yes")
                sys.exit()
    print("No")


if __name__ == "__main__":
    main()
