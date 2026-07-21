n=int(input())
count=0

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

l=factorization(n) 

for i in range(len(l)):
    m=l[i]
    m2=m[1]
    a=1
    while m2>=a:
        count+=1
        m2-=a
        a+=1
if n==1:
    print(0)
else:
    print(count)
