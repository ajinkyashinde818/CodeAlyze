def fac(n):
    dic = {}
    cur = n
    for i in range(2,(int(n**0.5)+2)):
        if cur % i == 0:
            count = 0
            while cur % i == 0:
                count += 1
                cur //= i
            dic[i] = count
            if cur == 1:
                break
    if cur != 1:
        dic[cur] = 1
    return dic

n = int(input())
ans = 0
for i in fac(n).values():
    count = 1
    while i >= count:
        i -= count
        count += 1
        ans += 1
print(ans)
