def prime_factor(x):
    
    prime_factor=[]
    
    for i in range(2,int(x**0.5)+1):
        if x==1: break

        count = 0
        while x%i == 0:
            x //= i
            count += 1
        if count>0:
            prime_factor.append((i,count))
    
    if x>1: prime_factor.append((x,1))
    
    return prime_factor

def count(x):
    ret = 1
    for i in range(1,x):
        if i*(i+1)//2 <= x:
            ret = i
        else:
            break
    return ret

n = int(input())
ans = 0
for p,esum in prime_factor(n):
    ans += count(esum)
print(ans)
