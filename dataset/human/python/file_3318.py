import collections
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

n = int(input())
if n == 1:
    print(0)
else:
    ans = 0
    c = factorization(n)
    for arr in c:
        m = arr[1]
        i = 1
        for _ in range(m):
            if i > m:
                break
            ans += 1
            m -= i
            i += 1
    print(ans)
