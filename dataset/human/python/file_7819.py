def main():
    n, k, s = map(int, input().split())
    ans = []
    for i in range(k):
        ans.append(str(s))
    for i in range(n-k):
        if s < 10**9:
            ans.append(str(s+1))
        else:
            ans.append('1')

    print(' '.join(ans))


main()
