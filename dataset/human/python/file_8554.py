def main():
    k,n=map(int,input().split())
    a=list(map(int,input().split()))
    d=[0]*n
    for i in range(1,n):
        d[i]=a[i]-a[i-1]
    d[0]=a[0]+k-a[n-1]
    d.sort()
    print(k-d[-1])

if __name__ == '__main__':
    main()
