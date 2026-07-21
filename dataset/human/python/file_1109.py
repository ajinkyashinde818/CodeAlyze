from collections import Counter
N = int(input())
A = list(map(int, input().split()))
B = list(reversed(list(map(int, input().split()))))

ac = Counter(A)
bc = Counter(B)

am = ac.most_common(1)[0]

if am[1]+bc[am[0]] > N:
    print("No")
    exit()

j = 0

for i in range(N):
    if A[i] == B[i]:
        while B[i]==A[j] or B[j]==A[i]:
            j += 1
            j %= N
        B[i], B[j] = B[j], B[i]

print("Yes")
print(*B)
