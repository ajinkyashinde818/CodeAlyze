import math
MOD=10**9+7
N=int(input())
x=list(map(int, input().split()))
y=[x[i+1]-x[i] for i in range(N-1)]
N_1=N-1
upp=math.factorial(N_1)%MOD
  
b=[0]*(N_1)
b[0]=upp
tmp=upp
out=b[0]*y[0]%MOD
for i in range(1, N_1):
  a=tmp*pow(i+1, MOD-2, MOD)%MOD
  b[i]=(b[i-1]+a)%MOD
  out+=b[i]*y[i]%MOD
  out%=MOD
print(out)
