from collections import Counter, deque
from random import randint

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

CA = Counter(A)
CB = Counter(B)
keys = set(A + B)
M = 0
for k in keys:
    M = max(M, CA[k] + CB[k])

if M > N:
    print('No')
    exit()

CB = CB.most_common()
L, R = [], []
for i, x in enumerate(CB):
    if i % 2 == 0:
        L.append(list(x))
    else:
        R.append(list(x))
X = deque(L + R[::-1])

y = L + R
ans = [None] * N
for i in range(N):
    if (X[0][0] != A[i]) and (X[-1][0] != A[i]):
        if X[0][1] > X[-1][1]:
            ans[i] = X[0][0]
            X[0][1] -= 1
            if X[0][1] == 0:
                X.popleft()
        else:
            ans[i] = X[-1][0]
            X[-1][1] -= 1
            if X[-1][1] == 0:
                X.pop()

    elif X[0][0] != A[i]:
        ans[i] = X[0][0]
        X[0][1] -= 1
        if X[0][1] == 0:
            X.popleft()
    else:
        ans[i] = X[-1][0]
        X[-1][1] -= 1
        if X[-1][1] == 0:
            X.pop()


for i in range(10):
    m = randint(0, N - 1)
    for i in range(N):
        if ans[i] != A[i]:
            continue
        ans[i], ans[m] = ans[m], ans[i]
        m += 1
        m %= N
print('Yes')
print(*ans, sep=' ')
