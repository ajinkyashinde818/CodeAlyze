def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    p = -1
    ans = 0
    for i, d in enumerate(a):
        if d == p+1:
            ans += b[d-1] + c[p-1]
        else:
            ans += b[d-1]
        p = d
    print(ans)




if __name__ == '__main__':
    solve()
