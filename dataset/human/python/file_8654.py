def find_d(a,k,n):
    d = a[0] + (k - a[n-1])
    point = 0
    
    for i in range(n-1):
        tmp = a[i+1] - a[i]
        if d<tmp:
            d = tmp
            point = i+1
    return d

if __name__ == "__main__":
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    d = find_d(a,k,n)
    
    print(k-d)
