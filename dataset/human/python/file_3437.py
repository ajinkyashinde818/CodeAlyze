n=int(input())
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
cnt=0

if n==1:
    print(0)
else:
    for num,i in l:
        p=1
        while i>0:
            cnt+=1
            i-=p
            p+=1
            if i<p:
                break
    print(cnt)
