def is_Prime(i):
    if i == 2:
        return True
    if i % 2 == 0 or i == 1:
        return False
    s = int(i ** (1 / 2))
    while True:
        if s == 1:
            return True
        if i % s == 0:
            return False
        s -= 1

def prime_factorize(n):
    ans = []
    for i in range(2, int(n ** (1 / 2)) + 1):
        while True:
            if not n % i == 0:
                break
            ans.append(i)
            n /= i
        if n == 1:
            break
    if n != 1:
        ans.append(int(n))
    return ans

n = int(input())
if n == 1:
    print(0)
    exit()
s = prime_factorize(n)
x = s[0]
t = []
c = 0
for i in s:
    if i == x:
        c += 1
    else:
        t.append(c)
        c = 1
        x = i
t.append(c)
ans = 0
for i in t:
    j = 1
    while True:
        if i - j < 0:
            break
        i -= j
        j += 1
        ans += 1
print(ans)
