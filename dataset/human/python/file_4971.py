p = 10**9+7
def pow(x,m):
    if m==0:
        return 1
    if m==1:
        return x
    if m%2==0:
        return (pow(x,m//2)**2)%p
    else:
        return (x*(pow(x,(m-1)//2)**2)%p)%p
N = int(input())
A = [1 for _ in range(N)]
for i in range(2,N):
    A[i] = (i*A[i-1])%p
X = list(map(int,input().split()))
X.insert(0,0)
cnt = 0
for i in range(1,N):
    cnt = (cnt+((X[N]-X[i])*pow(i,p-2))%p)%p
print((cnt*A[N-1])%p)
