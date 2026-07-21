n = int(input())
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
r = 0
for i, j in factorization(n):
    f = 1
    if i==1:
        break
    while j >= f:
        r += 1
        j -= f
        f += 1
print(r)
