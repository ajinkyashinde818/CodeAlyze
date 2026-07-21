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

L = []
L = factorization(n)
c = 0
#print(L)
if L[0][0] != 1:
    for i in range(len(L)):
        a = 1
        while L[i][1]>=a:
            L[i][1] = L[i][1]-a
            a += 1
            c += 1

print(c)
