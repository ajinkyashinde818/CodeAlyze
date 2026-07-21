import math
N=int(input())
i=2
A=N
app=0
for i in range(2, int(N**(1/2)+1)+1):
    suma=0
    sume=0
    while A%i==0:
        A=A/i
        suma+=1
    if suma>0:
        n=(-1+(1+8*suma)**(1/2))/2
        n=math.floor(n)
        n=int(n)
        app=app+n
    suma=0
    i+=1
if A>1:
    app+=1
if app>0:
    print(app)
if app==0:
    if N>1:
        print(1)
    if N==1:
        print(0)
