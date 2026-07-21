def mtoi(l):
    r=0
    c=1
    for i in l:
        if i=="m":
            r+=c*1000
            c=1
        elif i=="c":
            r+=c*100
            c=1
        elif i=="x":
            r+=c*10
            c=1
        elif i=="i":
            r+=c
            c=1
        else:
            c=int(i)
    return r


def itom(r):
    m=r//1000
    c=r//100-m*10
    x=r//10-m*100-c*10
    i=r-1000*m-100*c-10*x
    t=""
    if m:
        if m==1:t+="m"
        else:t+=str(m)+"m"
    if c:
        if c==1:t+="c"
        else:t+=str(c)+"c"
    if x:
        if x==1:t+="x"
        else:t+=str(x)+"x"
    if i:
        if i==1:t+="i"
        else:t+=str(i)+"i"
    return t

for _ in range(int(input())):
    l=input().split()
    print(itom(sum(map(mtoi,l))))
