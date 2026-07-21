def resolve():
    n = int(input())
    a = list(map(lambda num: int(num) - 1, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    res = 0
    for i in range(n):
        dish = a[i]
        res += b[dish]
        if i < n-1 and a[i] + 1 == a[i+1]:
            res += c[a[i]]

    print(res)



resolve()
