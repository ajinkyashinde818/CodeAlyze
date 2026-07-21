def factorization(n):
    arr = []
    for i in range(2, int(-(-n**0.5//1))+1):
        if n%i == 0:
            cnt=0
            while n%i == 0:
                cnt += 1
                n //= i
            arr.append([i, cnt])

    if n != 1:
        arr.append([n, 1])

    return arr
N = int(input())
ans = 0
if N != 1:
    fact_list = factorization(N)
    for _, i in fact_list:
        j = 1
        while i >= j:
            ans += 1
            i = i - j
            j += 1
            
print(ans)
