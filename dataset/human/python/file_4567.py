import math 
def prime(n):
    d = {}
    if n%2==0:
        d[2]=0
    while n % 2 == 0: 
        d[2]+=1
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2):
        if n%i==0:
            d[i]=0
        while n % i== 0: 
            d[i]+=1
            n = n / i 
    if n > 2:
        d[n]=1
    return d
def maxsum(di):
    ans = 0
    for i in di.items():
        c = 1
        x = 0
        y = i[1]
        while y-c>=0:
            #print(y, c, x)
            y-=c
            c+=1
            x+=1
        ans+=x
    return ans
di = prime(int(input()))
#print(di)
print(maxsum(di))
