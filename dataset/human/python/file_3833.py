def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
n=int(input())
if n==1:
    ans=0
else:
    a=prime_factorize(n)
    if a==[]:
        ans=1
    else:
        ans=0
        xzen=a[0]
        count=1
        ans+=1
        for x in range(1,len(a)):
            if xzen==a[x]:
                count+=1
                if count==3 or count==6 or count==10 or count==15 or count==21 or count==28 or count==36:
                    ans+=1
            else:
                xzen=a[x]
                count=1
                ans+=1
print(ans)
