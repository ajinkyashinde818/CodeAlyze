def start(k, n, a):
    max_distance=0
    for i in range(n-1):
        if(a[i+1]-a[i]>max_distance):
            max_distance = a[i+1]-a[i]
    if(k-a[-1]+a[0]>max_distance):
        max_distance = k-a[-1]+a[0]
    print(k-max_distance)

k,n = map(int, input().split())
a = list(map(int, input().split()))
start(k, n, a)
