n = int(input())

if n == 1:
    print(0)
    exit()

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

st = factorization(n)


count = 0
temp = 1


for a,b in st:

    while 1/2*(temp)*(temp +1) <= b:
        temp += 1
    count += temp-1
    temp = 1

print(count)
