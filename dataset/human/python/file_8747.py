def resolve():
    k,n=map(int, input().split())
    l=list(map(int, input().split()))
    a=0
    for i in range(n):
        if i!=0:
            a=max(l[i]-l[i-1],a)
        else:
            a=max(l[0]+k-l[-1],a)
    print(k-a)
resolve()
