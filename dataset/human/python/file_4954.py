def modinv2(a,m):
    return pow(a,m-2,m)

def f(n,m):
    a = 1
    for i in range(2,n+1):
        a = a*i%m
    return a

N = int(input())
x = list(map(int,input().split()))

ans = 0
P = 10**9+7

b = f(N-1,P)

invlist = [1]

for i in range(1,N-1):
    inv = (invlist[-1]+modinv2(i+1,P))%P
    invlist.append(inv)
#print(invlist)

for i in range(N-1):
    l = x[i+1]-x[i]
    ans += (l*invlist[i]%P)*b%P

print(ans%P)
