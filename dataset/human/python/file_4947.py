N = int(input())
A = [int(a) for a in input().split()]
    
def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

mod = 10**9+7 #出力の制限
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )

L = [1]*N
for i in range(1, N):
    L[i] *= L[i-1]*i
    L[i] %= mod
    
ans = 0
for i in range(1, N):
    ans += cmb(N-1, N-i, mod)*L[i-1]*L[N-i-1]*(A[N-1]-A[i-1])
    ans %= mod
        
L2 = [0]*(N-1)
for i in range(N-1):
    L2[i] = A[i+1]-A[i]

S = [0]*N
for i in range(N-1):
    S[i+1] = S[i] + L2[i]
    
L3 = [0]*N
for i in range(1, N):
    if N-i-1 >= i:
        L3[i] = L3[i-1] + S[N-i-1] - S[i-1]
    else:
        L3[i] = L3[N-i-1]

for t in range(1, N-1):
    ans += cmb(N-1, t+1, mod)*L[N-t-2]*L[t-1]*L3[t]
    ans %= mod
        
print(ans)
