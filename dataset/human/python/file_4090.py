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
N = int(input())
if N == 1:
    print(0)
    exit()
count = 0
lis = factorization(N)
for l in lis:
    num = l[1]
    for i in range(1,l[1]+1):
        if i > num:
            break
        num -= i
        i += 1
        count += 1
print(count)
