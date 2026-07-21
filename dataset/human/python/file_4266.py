def solve():
    N=n=int(input())
    q=int(n**0.5)
    ans=0
    for d in range(2,q+1) :
        a=0
        while n % d == 0 :
            a+=1
            n//=d
        if a>0 :
            ans+=int(((a*8+1)**0.5-1)/2)
    if n > 1 :
        ans+=1
    return ans

print(solve())
