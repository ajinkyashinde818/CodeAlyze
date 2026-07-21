def prime(n):
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





n=int(input(""))
s=0
if(n!=1):
    

    

    t=0
    lista=prime(n)
    #print(lista)
    
    c=lista[0]
    for i in lista:
        if (c==i):
            t+=1
        else:
            k=1
            while(t>=k):
                t-=k
                s+=1
                k+=1
            t=1
            c=i


    k=1
    while(t>=k):
        t-=k
        s+=1
        k+=1
        


            
        
        
    
    


print(s)
