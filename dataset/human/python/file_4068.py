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

a = int(input())

fact = factorization(a)

count = 0

for tup in fact:
    countTup = 0
    while True:
        countTup += 1
        if tup[1] < countTup:
            break
        tup[1] -= countTup
    count += countTup - 1

if a == 1:
    print(0)
else:
    print(count)
