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

res = 0
for _, x in factorization(N):
    i = 1
    while i <= x:
        res += 1
        x -= i
        i += 1
if N == 1:
    print(0)
else:
    print(res)
