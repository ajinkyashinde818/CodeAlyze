from collections import deque
n = int(input())
i = 2
a = []
x = n
while(i * i <= n):
    if (n % i == 0):
        a.append(i)
        n //= i
        while(n % i == 0):
            n //= i
            a.append(a[-1] * i)
    i += 1
if (n != 1):
    a.append(n)
a.sort(reverse = True)
ans = 0
while(x != 1 and len(a)):
    while(x % a[-1]):
        a.pop()
        if (len(a) == 0):
            break
    if (len(a) == 0):
        break
    x //= a[-1]
    a.pop()
    ans += 1
print(ans)
