def solve(n, a, b, c):
    res = 0
    for i in range(n):
        if (i + 1 < n) and (a[i+1] == a[i] + 1):
            res += c[a[i]-1]
        res += b[a[i]-1]
    return res

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
print(solve(n, a, b, c))
