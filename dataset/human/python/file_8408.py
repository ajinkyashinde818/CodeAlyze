def multi_input():
    return map(int, input().split())

N, K = multi_input()
A = list(map(int, input().split()))

d = [N-A[-1]+A[0]]
for i in range(1, K):
    d.append(A[i]-A[i-1])
    
s = sum(d)
mn = s
for i in range(K):
    mn = min(mn, s-d[i])
print(mn)
