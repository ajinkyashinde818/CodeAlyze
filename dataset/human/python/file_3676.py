n=int(input())
if n==1:
    print(0)
else:
    lst=[]
    i=2
    while i**2<=n:
        if n%i==0:
            n//=i
            lst.append(i)
            continue
        i+=1
    lst.append(n)
    from collections import Counter
    dic=dict(Counter(lst))
    s=0
    for i in dic:
        n=dic[i]
        k=0
        while n>=0:
            s+=1
            k+=1
            n-=k
        s-=1
    print(s)
