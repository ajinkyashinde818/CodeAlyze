n=int(input())

def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    divisors.sort()
    return divisors

def prime_fact(x):
    fact=[]
    for i in range(2, int(x**(0.5))+1):
        while x%i==0:
            fact.append(i)
            x//=i
    if x!=1:
        fact.append(x)
    if not fact:
        fact=[x]
    return fact

divisors=make_divisors(n)
divisors.pop(0)
cnt=0
for div in divisors:
    # print(n,div)
    # print(div, prime_fact(div), set(prime_fact(div)))
    if len(set(prime_fact(div)))==1 and n>1 and n%div==0:
        n//=div
        cnt+=1
    elif n<1:
        break
print(cnt)
