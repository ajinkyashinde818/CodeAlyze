if __name__ == '__main__':
    n = int(input())
    a = [int(s) - 1 for s in input().split()]
    b = [int(s) for s in input().split()]
    c = [int(s) for s in input().split()]
    ans = b[a[0]]
    for i, v in enumerate(a[1:]):
        ans += b[v]
        if v - a[i] == 1:
            ans += c[v - 1]
    print(ans)
