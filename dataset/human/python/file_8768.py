import sys
input = sys.stdin.readline

k,n=map(int,input().split())
a=[int(x) for x in input().split()]
a.sort()
mini=a[n-1]-a[0]
for i in range(n):
    if 0<i<n-1:
        mini=min(mini,min(abs(a[i]-a[i+1]+k)%k,(a[(i-1)%n]-a[i]+k)%k))
    else:
        if i==0:
            mini=min(mini,a[i]-a[i+1]+k)
        else:
            mini=min(mini,a[i-1]-a[i]+k)
print(mini)
