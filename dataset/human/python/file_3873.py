def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)

    if temp!=1:
        arr.append(1)



    return arr

N=int(input())
count_list=factorization(N)
ans=0
for k in range(0,len(count_list)):
    dlt=1
    c=count_list[k]
    while (c-dlt)>=0:
        c=c-dlt
        dlt+=1
        ans+=1
print(ans)
