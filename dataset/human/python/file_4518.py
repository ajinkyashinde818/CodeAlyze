n = int(input())
ans = 0
aaa = 2
maxi = 2
def prime(aaa):
    global primemode
    if n != 1:
        i = 2
        while i*i <= aaa:
            if aaa % i == 0:
                primemode = False
                return False
            i += 1
        return True
    else:
        return False
def make_divisors(n):
    if prime(n):
        return True
    a = 0
    i = 2
    while i <= n:
        if n % i == 0:
            if a == 0:
                a = i
                n /= i
                i -= 1
                if n == 1:
                    return True
            elif a == i:
                n /= i
                i -= 1
                if n == 1:
                    return True
                pass
            else:
                return False
        i += 1
    return True
def divisors(a, i):
    global ans, aaa, maxi, primemode
    while i <= n and i <= a:
        if i * i <= a and primemode:
            if prime(a):
                ans += 1
                break
        if a % i == 0:
            if make_divisors(i):
                primemode = True
                ans += 1
                num = a / i
                aaa = num
                if maxi <= i:
                    maxi = i
                divisors(num, i+1)
                break
        i += 1
if n == 1:
    print(0)
else:
    if prime(n):
        print(1)
    else:
        divisors(n, 2)
        print(ans)
