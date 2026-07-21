N = int(input())

def prime_factorize(n):
    prime_list = []
    tmp = n
    if n == 1:
        return []
    for i in range(2,int(n**0.5)+1):
        if tmp % i == 0:
            while tmp % i == 0:
                tmp = tmp // i
                prime_list.append(i)
                
    if tmp != 1:
        prime_list.append(tmp)
        
    if len(prime_list) == 0:
        return [n]
    else:
        return prime_list


import collections
c = collections.Counter(prime_factorize(N))

tmp = []
for i in range(1,40):
    tmp.append((1+i)*i//2)
import bisect
ans = 0
for i in list(c.values()):
    ans += bisect.bisect_right(tmp,i)
print(ans)
