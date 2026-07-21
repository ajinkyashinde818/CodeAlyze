def main():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    ans = k
    buf = 0
    a.append(k+a[0])
    for i in range(n):
        if buf < a[i+1] - a[i]:
            buf = a[i+1] - a[i]
    print(k - buf)

if __name__ == "__main__":
    main()
