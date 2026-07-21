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
ans = 0

if(N>1):
    Q = factorization(N)
    A = [ b for [a,b] in Q]
    for a in A:
        i = 1
        while(a >= i):
            a -= i
            i += 1
            ans += 1
    print(ans)

else:
    print(0)
