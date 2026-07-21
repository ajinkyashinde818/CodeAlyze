def my_prime(n:int):
    if n <= 1:
        return {}
    fac = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            while temp%i==0:
                temp //= i
            fac.append(i)
    if temp!=1:
        fac.append(temp)
    if fac==[]:
        fac.append(n)
    return fac
n = int(input())
temp = n
cnt = 0
for x in my_prime(n):
    i=1
    while x**i <= n:
        if temp % x**i == 0:
            cnt += 1
            temp = temp // x**i
        i += 1
print(cnt)
