def resolve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    ans = 0
    prevdish = -1
    for i in range(n):
        dish = a[i]
        ans += b[dish-1]
        if prevdish == dish-1:
            ans += c[dish-2]
        prevdish = dish
    print(ans)
resolve()
