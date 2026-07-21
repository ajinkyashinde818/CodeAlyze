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

x = factorization(n) 

if n ==1:
    print(0)
    exit()

res = 0

for i in x:
    temp = 0
    for j in range(1,100):
        temp += j
        if i[1] < temp:
            res += (j-1)
            break

print(res)
