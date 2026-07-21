import math
def primeFactors(n):
    d=dict()
    while n % 2 == 0:
        if 2 in d:
            d[2]+=1
        else:
            d[2]=1
        n = n // 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):

        while n % i == 0:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
            n = n // i

    if n > 2:
        if n in d:
            d[n]+=1
        else:
            d[n]=1

    return d

def getcount(S):
    return int((math.sqrt(1+8*S)-1)/2)


n=int(input())

d = primeFactors(n)

total=0

for x in d:
    total+=getcount(d[x])

print(total)
