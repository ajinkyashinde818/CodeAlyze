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

def cnt(arr):
    c = 0
    n = arr[1]
    i = 1
    while True:
        if 0 <= n - i:
            c += 1
            n -= i
            i += 1
        else:
            break

    return c

arr = factorization(n)

ans = 0
if n != 1:
    for i in arr:
        ans += cnt(i)

print(ans)
