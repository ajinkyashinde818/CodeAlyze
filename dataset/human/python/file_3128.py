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
prime = factorization(n)
prime_array = []
for i in range(len(prime)):
    prime_array.append(prime[i][1])

ans = 0
for j in range(len(prime_array)):
    check = True
    num = 1
    test = 1
    while check == True:
        if prime_array[j] == num:
            check = False
            ans += test
        elif prime_array[j] < num:
            check = False
            ans += test - 1
        test += 1
        num += test
if n == 1:
    ans = 0
print(ans)
