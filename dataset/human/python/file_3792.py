def factorize(n):
    ans = 0 
    b, e = 2, 0  
    while b * b <= n:
        while n % b == 0:
            n = n // b
            e = e + 1
        if e > 0:
            ans += int((-1 + (1+8*e)**(1/2))/2)
        b, e = b + 1, 0
    if n > 1:
        ans += 1
    return ans

N = int(input())
print(factorize(N))
