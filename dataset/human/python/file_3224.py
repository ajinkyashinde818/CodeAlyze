n = int(input())
def factorize(n):
    a=[]
    while n%2==0:
        a.append(2)
        n//=2
    f=3
    while f*f<=n:
        if n%f==0:
            a.append(f)
            n//=f
        else:
            f+=2
    if n!=1:
        a.append(n)
    return a
li = []
for i in range(1,10):
    li.append(i*(i+1)//2)
sum1 = 0
a = factorize(n)
liset = set(a)
relist = list(liset)
for i in range(len(liset)):
    b = a.count(relist[i])
    for j in range(10):
        if b >= li[j] and b < li[j+1]:
            sum1 += j+1
            break
print(sum1)
