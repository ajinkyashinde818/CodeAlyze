from itertools import accumulate

K, N = map(int, input().split())
A = list(map(int, input().split()))
B = [a+K for a in A]
A.extend(B)

B = []
for i in range(1, len(A)):
    B.append(A[i]-A[i-1])

cum = [0]
cum.extend(list(accumulate(B)))

ans = float('inf')

for i in range(N-1, N*2):
    ans = min(ans, cum[i]-cum[i-N+1])

print(ans)
