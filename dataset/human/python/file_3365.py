n = int(input())

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

list_n = prime_factorize(n)
dic = {}
for i in list_n:
    if i in dic:
        dic[i]+=1
    else:
        dic[i]=1
ans = 0
for i in dic.values():
    count=0
    while True:
        count+=1
        if i>=count:
            i-=count
        else:
            ans+=count-1
            break
print(ans)
