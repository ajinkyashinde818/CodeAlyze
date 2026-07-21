N = int(input())


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

if N==1:
    print(0)
else:
    s=0
    d=factorization(N)
    for p in range(len(d)):
        i=1
        while(d[p][1]>0):
            if d[p][1]-i<0:
                d[p][1]=-1
            else:
                d[p][1]=d[p][1]-i
                s=s+1
                i=i+1
    print(s)
