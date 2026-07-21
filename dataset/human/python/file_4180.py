import collections
S = int(input())
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

l = prime_factorize(S)
x = collections.Counter(l)
X = list(x.values())

y = len(X)
ans = 0
for i in range(y):
    if 1 <=X[i] <= 2:
        ans +=1
    elif 3 <= X[i] <=5 :
        ans += 2
    elif 6<= X[i] <=9:
        ans +=3
    elif 10<= X[i] <=14:
        ans +=4
    elif 15<= X[i] <= 20:
        ans +=5
    elif 21 <= X[i] <= 27:
        ans +=6
    elif 28 <= X[i] <=35:
        ans +=7
    elif 36 <= X[i] <= 44:
        ans +=8
print(ans)
