n = int(input())

A = list(map(int,input().split()))

C = []
for i in range(n-1):
    C.append(A[i+1]-A[i])
n -= 1
A=C[:]

mod  =10**9+7

B = [0] * (n+1)


l=n+5
M = [1]  # i!のmod
m = 1
for i in range(1, l):
    m = (m * i) % mod
    M.append(m)

def inv(x, y):  # xのmod yでの逆元を返す関数
    yy = y - 2
    ans = 1
    while yy > 0:
        if yy % 2 == 1:
            ans = (ans * x) % y
        x = (x**2) % y
        yy //= 2
    return ans

for i in range(1, n+1):
    B[i] = (inv(i,mod) * M[n-1]) % mod


p=M[n]
ans = p*A[0]
for i in range(1, n):
    
    p = (p + M[n-1] + B[i+1]*(n-1-i)) % mod
    # print("p",p)
    ans = (ans+p*A[i]) % mod
print(ans%mod)
