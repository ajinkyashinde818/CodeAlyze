import collections
N = int(input())
S = input()
A = collections.Counter(S)
B = list("qwertyuiopasdfghjklzxcvbnm")
C = []
for i in B:
    C.append(A[i])
D = [i+1 for i in C if i != 0]
ans = 1
for i in range(len(D)):
    ans *= D[i]
print((ans-1)%(10**9 + 7))
