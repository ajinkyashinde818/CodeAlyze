N,K = map(int,input().split())
A = list(map(lambda x: int(x)-1,input().split()))
B = [0]*N

o = [0] * 63

def bi(x):
    i = 0
    while x != 0:
        o[i] = x%2
        x //= 2
        i += 1

bi(K)

n = 0
for i in range(63):
    if o[i]:
        n = A[n]
    for j in range(N):
        B[j] = A[A[j]]
    for j in range(N):
        A[j] = B[j]
        
print(n+1)
