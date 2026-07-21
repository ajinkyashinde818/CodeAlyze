def factorize(n):
    fct = []
    b,e = 2,0
    while b*b <= n:
        while n % b==0:
            n = n//b
            e += 1
        if e > 0:
            fct.append((b,e))
        b,e = b+1,0
    if n > 1:
        fct.append((n,1))
    return fct

n = int(input())
ans = 0
for i,j in factorize(n):
    ans += -(-int(((1 + 8*j)**(1/2) - 1 )/ 2))
print(ans)
