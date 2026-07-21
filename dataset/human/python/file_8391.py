def abc160c_traveling_salesman_around_lake():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    total = 0
    max_distance = 0
    for i in range(n - 1):
        total += a[i + 1] - a[i]
        max_distance = max(max_distance, a[i + 1] - a[i])
    total += k - a[n - 1] + a[0]
    max_distance = max(max_distance, k - a[n - 1] + a[0])
    print(total-max_distance)
abc160c_traveling_salesman_around_lake()
