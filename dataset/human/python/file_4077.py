import sys
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

n=int(input())
if n==1:
    print(0)
    sys.exit()
l=factorization(n)
ans =0
for x in l:
    a=x[0] #素数
    b=x[1] #素数の個数
    k=0
    t=0
    while(True):
        t += 1
        k += t
        if k==b:
            ans += t
            break
        elif k > b:
            ans += t-1
            break
print(ans)
