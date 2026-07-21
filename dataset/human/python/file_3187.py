from collections import defaultdict
n = int(input())

def soinsu(n):
    for i in range(2, int(n ** 0.5) + 1):
        while n % i == 0:
            n //= i
            S[i] += 1
    if S == {}:
        S[n]+=1
    else:
        if n != 1:
            S[n] += 1
    return S


if n==1:
    print(0)
else:
    S = defaultdict(int)
    S=soinsu(n)
    r=0
    for k,v in S.items():
        i=1
        while v>=i:
            v-=i
            r+=1
            i+=1
    print(r)
