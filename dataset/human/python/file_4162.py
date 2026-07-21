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

K = factorization(N)
cnt = 0
for k in K:
    x = k[1]
    i = 1
    while True:
        if i * (i - 1) // 2 <= x < i * (i + 1) // 2:

            cnt += i-1
            break
        i += 1
print(cnt)
