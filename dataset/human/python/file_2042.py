n = int(input())
s = input()
mod = 10**9 + 7

ans = 1
import string
A = [chr(i) for i in range(ord('a'), ord('z')+1)]
B = {}
for i in range(len(A)):
    B[A[i]] = i
C = [1] * 26

for i in range(n):
    C[B[s[i]]] += 1

for i in range(len(C)):
    ans = (ans * C[i]) % mod

print(ans-1)

# for i in range(n):
#     for j in range(26):
#         if j != B[s[i]]:
#             C[j] = ans * 2
#     ans += (ans - C[B[s[i]]])
#     print(C[:5],ans)

# print(ans-1)
