n = int(input())
cnt = 0

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
if n == 1:
    print(0)
    exit()
li = factorization(n)
for i in li:
    ii = i[0]
    loop = True
    while(loop):
        if n % ii == 0:
            n = n / ii
            cnt += 1
            ii *= i[0]
        else:
            loop = False
print(cnt)
