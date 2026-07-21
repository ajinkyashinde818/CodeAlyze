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

arr = factorization(N)

res = 0
for a,b in arr:
    tmp = 1
    while b >= tmp:
        b = b - tmp
        tmp += 1
        res = res + 1

if N == 1:
    print(0)
else:
    print(res)
