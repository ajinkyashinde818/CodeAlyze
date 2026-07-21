import math

N = int(input())

def judge(n):
    if n <= 1:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            n //= i
            while n != 1:
                if n % i != 0:
                    return False
                n //= i
            return True
    return True
ans = 0
i = 2
limit = int(math.sqrt(N))
while N != 1:
    
    if i > limit:
        if N > i:
            ans += 1
        break
    if N % i == 0 and judge(i): 
        N //= i
        ans += 1
        
    i += 1
    
print(ans)
