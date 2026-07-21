n = int(input())
def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    divisors.sort()
    return divisors
p = make_divisors(n)
x = 0
i = 1
ans = 0
def countf(x):
    for j in range(1,x+2):
        if (1+j)*j//2 > x:
            return j - 1
while n != 1:
    if n % p[i] == 0:
        x += 1
        n = n // p[i]
    else:
        if x != 0:
            ans += countf(x)
            x = 0
        i += 1
ans += countf(x)
print(ans)
