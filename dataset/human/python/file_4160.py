N = int(input())
if N <= 1:
    print('0')
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

r = 0
for n, i in factorization(N):
    m = 1
    while i >= m:
        i -= m
        m += 1
        r += 1
print(r)
