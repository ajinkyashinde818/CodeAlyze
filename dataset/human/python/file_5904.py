if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    d = a[0]
    sums = 0
    for i in range(1, n):
        if a[i] - d == 1:
            sums += c[a[i-1]-1]
        d = a[i]
    for j in range(n):
        sums += b[j]
    print(sums)
