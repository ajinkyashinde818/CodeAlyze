N=int(input())
def prime_factorization(n):
    p={}
    for i in range(2,int(n**.5)+1):
        x=0
        while n%i==0:
            n//=i
            x+=1
        if x:
            p[i]=x
    if n>1:
        p[n]=1
    return p
p=prime_factorization(N)
x=0
for v in p.values():
    y=0
    while y<v:
        x+=1
        y+=1
        v-=y
print(x)
