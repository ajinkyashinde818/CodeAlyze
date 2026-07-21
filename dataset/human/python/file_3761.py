import collections
 
def primes(n): #試し割り法で各素因数とその指数を求める
 cnt=collections.defaultdict(int)
 for i in range(2,int(n**0.5)+1):
   if n%i==0:
     while n%i==0:
       cnt[i]+=1
       n//=i
 if n!=1:
   cnt[n]+=1
 return cnt
 
n=int(input())
cnt=primes(n)
ans=0
for key in cnt.keys():
    val=cnt[key]
    for i in range(100): #各素因数の指数について、k(k+1)//2<=(指数)を満たす最大のkを求める
        if (i*(i+1))//2>val:
            ans+=i-1
            break
print(ans)
