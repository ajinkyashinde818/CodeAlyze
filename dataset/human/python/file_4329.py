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
N=int(input())
if N==1:
    print(0)
else:
    l=[]
    for i in range(0,len(factorization(N))):
        l.append(factorization(N)[i][1])
    l.sort(reverse=True)
    s=0
    t=1
    while l[0]>0:
        for i in range(0,len(l)):
            if l[i]>=t:
                s += 1
            l[i]-=t
        t+=1
    print(s)
