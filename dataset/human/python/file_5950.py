def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    cnt = 0
    for i in range(n):
        cnt += b[a[i] - 1]
        if i > 0 and a[i] == a[i-1] + 1:
            cnt += c[a[i-1] - 1]
    print(cnt)

if __name__ == '__main__':
    main()
