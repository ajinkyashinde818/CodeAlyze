def intminus(a):
    return int(a) - 1


N = int(input())
A = list(map(intminus, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))


ans = B[A[0]]
pre = A[0]
for i in range(1, N):
    ans += B[A[i]]
    if A[i] == pre + 1:
        ans += C[pre]
    pre = A[i]

print(ans)
