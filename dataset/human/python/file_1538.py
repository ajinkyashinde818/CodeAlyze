def main():
    n, m = map(int, input().split())

    a = [input() for _ in range(n)]
    b = [input() for _ in range(m)]

    for i in range(n - m + 1):
        j = a[i].find(b[0])
        while j != -1:
            if judge(a, b, m, i, j):
                print('Yes')
                return
            j = a[i].find(b[0], j + 1)
    print('No')

def judge(a, b, m, i, j):
    for k in range(m):
        if a[i + k][j:j+m] != b[k]:
            return False
    return True

main()
