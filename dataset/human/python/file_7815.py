def main():
    n, k, s = map(int, input().split())
    if k == 0:
        if s != 10**9:
            ans = [10**9]*n
        else:
            ans = [1]*n
    else:
        if s == 10**9:
            ans = ([s]*k)+([1]*(n-k))
        else:
            ans = [s]*(k)+[10**9]*(n-k)
    print(*ans)


main()
