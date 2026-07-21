import copy
a = [int(c) for c in input().split()]
K = a[0]
N = a[1]
A = [int(c) for c in input().split()]
B = list(map(lambda x: x+K,copy.deepcopy(A)))
A = A+B
l = 0
tmp = 0
cnt = 0
for i in range(N):
    tmp = A[i+1]-A[i]
    if tmp > l :
        cnt = i
        l = tmp

print(K-l)
