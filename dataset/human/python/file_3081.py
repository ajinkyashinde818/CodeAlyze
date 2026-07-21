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
A = int(input())

if A == 1:
    print(0)
else:
    ls = factorization(int(A)) 
    ans = 0
    for n in range(len(ls)):
        ans += int((ls[n][1]*2 +1/4)**(1/2)-(1/2))
    print(ans)
