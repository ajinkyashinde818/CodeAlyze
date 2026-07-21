import sys
n = int(input())

def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr


fn = factorization(n)

memo = {}
def f(a):
    fa = a
    if a in memo:
        return memo[a]
    if a == 1:
        memo[1] = 1
        return 1
    else: # a>1
        i = 1
        ret = 0
        while a >= i:
            a-=i
            i+=1
            ret+=1
        memo[fa] = ret
        return ret

ans = 0
for u, v in fn:
    ans+=f(v)
if n == 1:
    print(0)
else:
    print(ans)
