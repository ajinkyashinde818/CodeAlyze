N = int(input())
def factorize(N):
    n = N
    r = []
    for i in range(2,int(N**0.5)+1): # intに変換すること
        cnt = 0
        while(n%i==0):
            cnt += 1
            n //= i #  整数除算(//)を使うこと
        if cnt!=0:
            r.append((i,cnt))
    if n!=1:
        r.append((n,1))
    return r

ans = 0
for _, cnt in factorize(N):
    i = 1
    while(i <= cnt):
        cnt-=i
        i+=1
        ans+=1
print (ans)
