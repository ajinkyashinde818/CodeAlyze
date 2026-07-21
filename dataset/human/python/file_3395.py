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
def wa(x):
    return x*(x+1)/2

ans = []
n = int(input())
if n == 1:
    print(0)
else:
    fac = factorization(n)
    for i in range(len(fac)):
        j = 1
        while True:
            if wa(j) <= fac[i][1] and fac[i][1] < wa(j+1):
                break
            else:
                j += 1
        ans.append(j)
    print(sum(ans))
