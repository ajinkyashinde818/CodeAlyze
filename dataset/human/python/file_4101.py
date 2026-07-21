def make_divisors(n):
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]
n = int(input())
l = make_divisors(n)
ans = 0
for i in range(1, len(l)):
    cnt = 0
    while n % l[i] == 0:
        cnt += 1
        n //= l[i]
    i = 1
    while True:
        if cnt - i >= 0:
            ans += 1
            cnt -= i
            i += 1
        else:
            break
print(ans)
