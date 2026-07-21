def get_sieve_of_eratosthenes_new(n):
    import math
    if not isinstance(n, int):
        raise TypeError('n is int type.')
    if n < 2:
        raise ValueError('n is more than 2')
    prime = []
    limit = math.sqrt(n)
    data = [i + 1 for i in range(1, n)]
    while True:
        p = data[0]
        if limit <= p:
            return prime + data
        prime.append(p)
        data = [e for e in data if e % p != 0]

prime=get_sieve_of_eratosthenes_new(10**6)

def ind(b,n):
    res=0
    while n%b==0:
        res+=1
        n//=b
    return res

N=int(input())
count={p:0 for p in prime}
for p in prime:
    a=ind(p,N)
    count[p]=a
    N//=p**a

if N!=1:
    count[N]=0
    count[N]=1

res=0
for p in count:
    if count[p]:
        t=(2*count[p])**0.5
        t=int(t)
        if 2*count[p]>=t*(t+1):
            res+=t
        else:
            res+=t-1

print(res)
