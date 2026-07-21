def main():
    N = int(input())
    l = list(map(int, input().split()))
    ans = int(2e+9)
    X = sum(l)
    x = 0
    for i in range(N-1):
        x += l[i]
        ans = min(ans, abs(X-2*x))
    print(ans)
if __name__ == '__main__':
    main()
