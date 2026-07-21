def main():
    n = int(input())
    a = list(map(int,input().split()))
    m = 0
    for i in range(n):
        if a[i]<0:
            m += 1
    ans = 0
    for i in range(n):
        ans += abs(a[i])
    if m%2==0:
        print(ans)
    else:
        mi = float('inf')
        for i in range(n):
            if mi>abs(a[i]):
                mi = abs(a[i])
        print(ans-2*mi)

if __name__ == "__main__":
    main()
