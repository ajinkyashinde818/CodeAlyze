from collections import Counter
N, K = map(int,input().split())
A = list(map(int,input().split()))
i = k = 0
B = [1]
for i in range(N):
    B.append(A[B[i]-1])

S = Counter(B)
idx = S.most_common(1)[0][0]
i = k = cnt = 0
k_s = None

while k < N:
    if B[k] == idx and cnt == 1:
        k_s = k
        break
    elif B[k] == idx:
        k_f = k
        cnt += 1
    k += 1
if k_s and k_s < K:
    k_max = (K - B.index(idx)) % (k_s - k_f) + B.index(idx)
else:
    k_max = K
i = k = 0
while k < k_max:
    i = A[i] - 1
    k += 1
print(i + 1)
