def main():
    n = int(input())
    A = list(map(int, input().split()))
    tot = sum(A)
    s = 0
    ans = float('inf')
    for a in A[:-1]:
        s += a
        ans = min(ans, abs(2 * s - tot))
    print(ans)

if __name__ == '__main__':
    main()
