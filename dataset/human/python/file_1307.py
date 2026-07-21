def main():
    _ = int(input())
    a = list(map(int,input().split()))

    sm = sum(a)
    sn = a[0]
    ar = sm - a[0]
    ans = abs(sn - ar)

    for i in range(1,len(a)-1):
        sn += a[i]
        ar -= a[i]
        ans = min(ans,abs(sn-ar))

    print(ans)

if __name__ == "__main__":
    main()
