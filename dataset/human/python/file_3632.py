N = int(input())

if N == 1:
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


fact_list = factorization(N)

res = 0
for k, v in fact_list:
    cnt = 1
    while True:
        v -= cnt

        if v == 0:
            res += 1
            break

        if v < 0:
            break

        cnt += 1
        res += 1

print(res)
