import math
def Sieve_of_Eratosthenes(N):
    if N<2:
        prime = [False for i in range(N+1)]
        return prime
 
    prime = [True for i in range(N+1)]
    prime[0] = False
    prime[1] = False
 
    for i in range(2, int(N**0.5)+1):
        if prime[i]:
            for j in range(i*2, N+1, i):
                prime[j] = False
 
    return prime

n=int(input())
prime=Sieve_of_Eratosthenes(int(n**0.5)+100)
ans=0
for p in range(len(prime)):
    if prime[p]==True:
        tp=p
        while n%tp==0:
            ans+=1
            n//=tp
            tp*=p
        
        while n%p==0:
            n//=p
if n!=1: ans+=1
print(ans)
