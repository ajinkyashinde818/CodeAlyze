def slove():
    import sys
    input = sys.stdin.readline
    n, m = list(map(int, input().rstrip('\n').split()))
    a = [list(str(input().rstrip('\n'))) for _ in range(n)]
    b = [list(str(input().rstrip('\n'))) for _ in range(m)]
    for i in range(n - m + 1):
        for j in range(n - m + 1):
            b_y = True
            for k in range(i, i + m):
                for l in range(j, j + m):
                    if a[k][l] != b[k-i][l-j]:
                        b_y = False
                        break
            if b_y:
                print("Yes")
                exit()
    print("No")


if __name__ == '__main__':
    slove()
