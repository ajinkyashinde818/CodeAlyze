def prime_factorization(n):
    if n == 1:
        return []
    ret = []
    tmp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if tmp%i==0:
            cnt=0
            while tmp%i==0:
                cnt+=1
                tmp//=i
            ret.append([i, cnt])
    if tmp!=1:
        ret.append([tmp,1])
    if ret==[]:
        ret.append([n,1])
    ret.sort()
    return ret

N = int(input())
P = prime_factorization(N)
ans = 0

for prime in P:
    cnt = 1
    while cnt <= prime[1]:
        ans += 1
        prime[1] -= cnt
        cnt += 1
print(ans)
