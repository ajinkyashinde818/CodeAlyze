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



n = int(input())
l = factorization(n)
ans = 0



if n == 1:
    ans = 0
elif l[0][0] == n:
    ans = 1

else:
    l2 = []
    s = set()

    for i in l:

        for j in range(1,9999999999):
            if i[1]*2 < j*(j+1):
                ans += j-1
                break

    
print(ans)
