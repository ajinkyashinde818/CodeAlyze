import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))  #空白あり


N = I()
X = LI()
mod = 10**9+7
Y = [X[i+1]-X[i] for i in range(N-1)]

r = 1  # (N-1)!
for i in range(1,N):
    r *= i
    r %= mod

C = [r]  # Ci = (N-1)!*(1/1+1/2+…+1/i)
for i in range(2,N):
    C.append((C[-1]+r*pow(i,mod-2,mod)) % mod)

ans = 0
for y,c in zip(Y,C):
    ans += y*c
    ans %= mod

print(ans)
