import statistics
K,N = map(int,input().split())
A = [int(n) for n in input().split()]

a1 = max(A)-min(A)

max_v = 0
A_i = None
for i in range(len(A)-1):
    if (A[i+1]-A[i])>max_v:
        max_v = A[i+1]-A[i]
        A_i = i+1

a2 = A[A_i-1]+abs(K-A[A_i])
print(a2) if a1>a2 else print(a1)
