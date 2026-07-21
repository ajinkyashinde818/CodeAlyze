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

n= int(input(''))

plist = prime_factorize(n)

import collections
c = collections.Counter(plist)

#print(c)
cnt=0
for k,v in c.items():
    cnt2=0
    idx=0
    while True:
        idx+=1
        cnt2+=idx
        if cnt2 > v:
            break
        else:
            cnt+=1
#        print("{}:{}  {} <= {}".format(k,v,cnt,cnt2))        

print(cnt)
