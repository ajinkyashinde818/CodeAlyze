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
n=int(input())
t=prime_factorize(n)
t.append(0)
count=0
num=1
answer=0
for i in range(len(t)-1):
    if num==1:
        answer+=1
        if t[i]==t[i+1]:
            num+=1
    else:
        count+=1
        if t[i]!=t[i+1] and count!=num:
            num=1
            count=0
        elif count==num:
            answer+=1
            count=0
            if t[i]==t[i+1]:
                num+=1
            else:
                num=1
if n==1:
    answer=0
print(answer)
