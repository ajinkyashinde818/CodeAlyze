N = int(input())

def factoring(M,n=2):
    if M==1: return {}
    for i in range(n,int(M**0.5)+1):
        if M%i==0:
            ret = factoring(M//i,i)
            ret[i] = ret.get(i,0)+1
            return ret
    return {M:1}

F = factoring(N)

ans = 0
for n in F.values():
    tmp = 1
    while n >= tmp:
        n -= tmp
        ans += 1
        tmp += 1

print(ans)
