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

    return arr

N=int(input())

ls=factorization(N)

cnt=0

for l in ls:
    cc=0
    for i in range(1,l[1]+1):
        cc+=i
        if cc<=l[1]:
            cnt+=1
        else:
            break

print(cnt)
