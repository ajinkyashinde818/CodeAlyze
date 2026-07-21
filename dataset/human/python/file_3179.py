def div(c,n):
    d={}
    while(n%2==0):
        n=n//2
        if(2 in d):
            d[2]+=1
        else:
            d[2]=1
    for i in range(3,int(n**0.5)+1):
        while(n%i==0):
            n=n//i
            if(i in d):
                d[i]+=1
            else:
                d[i]=1
    if(n>1):
      d[n]=1
      if(n==c):
          return 1
    su=0
    for i in d:
        f=d[i]*2
        su+=(-1+(int((1+4*f)**0.5)))//(2)
    return su
            
n=int(input())
c=n
print(div(c,n))
