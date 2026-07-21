n = int(input())
def prime(n):
    p = []
    flag = [True] * (n - 1)
    for i in range(n - 1):
        if flag[i] == True:
            p.append(i + 2)
            num = i
            while num <= n - 2:
                flag[num] = False
                num += i + 2
    return p
p =prime(int(n ** 0.5 + 1))
p2 = {}
for i in p:
    while True:
        if n % i == 0:
            p2.setdefault(i, 0)
            p2[i] += 1
            n //= i
        else:
            break
if n != 1:
    p2[n] = 1
if not p2:
    print(0)
else:
    ans = 0
    for i in p2.values():
        num = 1
        while i >= num:
            ans += 1
            i -= num
            num += 1
    print(ans)
