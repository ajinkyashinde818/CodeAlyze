n = int(input().strip())

def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n /= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table

prefix=[1]*40
for i in range(1,40):
    prefix[i]=prefix[i-1]+i+1

ans=0
prime_table=prime_decomposition(n)
i=0
while i <len(prime_table):
    length=1
    while i<len(prime_table)-1 and prime_table[i+1]==prime_table[i]:
        length+=1
        i+=1
    i+=1
    for j in range(40):
        if prefix[j]>length:
            break
    ans+=j
print(ans)
