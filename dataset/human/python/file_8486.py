def main():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    cost = a[n-1]-a[0]
    for i in range(n-1):
        cost = min(cost, k-(a[i+1]-a[i]))
    print(cost)

if __name__ == "__main__":
    main()
