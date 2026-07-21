import math
n = int(input())
def prime_factorization(n):
    arr = []
    temp = n
    for i in range(2, int(math.sqrt(temp)) + 1):
        if n%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            if cnt != 0:
                arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr
if n == 1:
    print(0)
elif len(prime_factorization(n)) == 1 and prime_factorization(n)[0][1] == 1:
    print(1)
else:
    ans = 0
    prime_list = prime_factorization(n)
    # print(prime_list)
    for i in prime_list:
        a = i[1]
        sub = 1
        j = 0
        while True:
            if a < sub:
                break
            a -= sub
            sub += 1
            j += 1
            
        #     print(a, sub, j)
        # print(j, i[1])
        ans += j
        
    print(ans)
