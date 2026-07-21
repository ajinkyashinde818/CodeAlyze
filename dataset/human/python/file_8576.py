kn = list(map(int,input().split()))
k = kn[0]
n = kn[1]
A = list(map(int,input().split()))

def find_max(a,n,k):
    m = a[0] + (k-a[n-1])
    for i in range(1,n):
        if a[i]-a[i-1] > m:
            m = a[i]-a[i-1]
    return m

print(k-find_max(A,n,k))
