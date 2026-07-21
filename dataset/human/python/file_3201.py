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

comb = factorization(n)
lst = []
for i in comb:
    for j in range(i[1]):
        lst.append(i[0]**(j+1))

lst.sort()
ans = 0
for i in lst:
    if n == 1:
        break
    elif n > 1:
        if n%i == 0:
            n = n/i
            ans += 1
print(ans)
