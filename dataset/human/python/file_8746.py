def main():
    k, n = map(int, input().split())
    a = [int(i) for i in input().split()]
    r = [a[i+1] - a[i] for i in range(n-1)]
    if a[-1] - a[0] < k/2.:
        r.append(a[-1]-a[0])
    else:
        r.append(a[0] + k - a[-1])
    rmax = max(r)
    ans = k - rmax
    print(ans)

if __name__ == "__main__":
    main()
