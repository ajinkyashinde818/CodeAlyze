def prime_factor(n):
    ass = []
    for i in range(2,int(n**0.5)+1):
        while n % i==0:
            ass.append(i)
            n = n//i
    if n != 1:
        ass.append(n)
    return ass

n = int(input())
ass = prime_factor(n)
cnt = {}
for x in ass:
    if x not in cnt:
        cnt[x] = 1
    else:
        cnt[x] += 1
#print(cnt)
ass = set(ass)
ans = 0
for x in ass:
    i = 1
    c = cnt[x]
    while c >= i:
        c -= i
        ans += 1
        i += 1

print(ans)
#print(ass)
