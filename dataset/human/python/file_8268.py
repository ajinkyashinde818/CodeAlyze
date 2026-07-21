def main():
    n=int(input())
    a=list(map(int,input().split()))
    s=sum(a)
    if s%(n*(n+1)//2) != 0:
        return "NO"
    k=s//(n*(n+1)//2)
    for i in range(n-1):
        if (a[i]-a[i+1]+k)%n!=0 or a[i+1]-a[i]>k or a[i+1]-a[i]<k*(1-n):
            return "NO"
    if (a[-1]-a[0]+k)%n!=0:
        return "NO"
    return "YES"

print(main())
