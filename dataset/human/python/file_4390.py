n=int(input())
factors=[]
i=2
def checker(power):
    l=1
    r=20
    ans=1
    while l<=r:
        mid=l+(r-l)//2
        if mid*(mid+1)/2<=power:
            ans=mid
            l=mid+1
        else:
            r=mid-1
    return ans
while i**2<=n:
    if n%i==0:
        cnt=0
        while n%i==0:
            n/=i
            cnt+=1
        factors.append([i,cnt])
    i+=1
if n>1:
    factors.append([n,1])

res=0
rem=0
for i in range(len(factors)):
    a=checker(factors[i][1])
    res+=a
    factors[i][1]-=a
    rem+=factors[i][1]
'''if rem>1:
    res+=rem*(rem-1)/2'''
#print(factors)
print(int(res))
