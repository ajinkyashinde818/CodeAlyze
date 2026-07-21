N = int(input())

from collections import defaultdict
def factorize(n):
    dd = defaultdict(int)
    for i in range(2,int(n**0.5)+1):
        while n%i==0 and n>0:
            dd[i]+=1
            n//=i
    if n>1:
        dd[n]+=1
    return dd

dd = factorize(N)

def check(num):
    count = 0
    for i in range(1,101):
        if count > num:
            break
        count += i
    return i-2

ans = 0
for key in dd:
    ans +=check(dd[key])

print(ans)
