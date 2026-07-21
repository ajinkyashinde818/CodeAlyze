import math

n = int(input())
nroot = int(math.sqrt(n)) +1

result = {}

for i in range(2,nroot+1):
    while n%i==0:
        if i in result:
            result[i] +=1
        else:
            result[i] = 1
        
        n = n//i
if (n>nroot):
    result[n] = 1

ans = 0
for _, i in result.items():
    r = 1
    add = 0
    while  i >= r:
        i -=  r
        r +=1
        add +=1
    
        
    ans += add
if ans > 0:
    print(ans)
else:
    if n > 1:
        print(1)
    else:
        print(0)
