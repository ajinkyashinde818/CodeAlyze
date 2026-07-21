N = int(input())
d = list( map(int, input().split() ) )
kai = 1
mod = 10**9+7
result = 0

def modinv(a, mod=10**9+7):
    return pow(a, mod-2, mod)

for i in range(1,N):
    kai = (kai%mod)*i

for i in range(N-1):    
    result += ( kai * (d[N-1] - d[i]) * modinv(i+1) ) % mod 

print( result%mod )
