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

lst = factorization(n)
res = 0
for elem1, elem2 in lst:
    cnt = 1
    if elem1 == 1:
        continue
    while elem2 >= cnt:
        elem2 -= cnt
        cnt += 1
        res += 1
print(res)
