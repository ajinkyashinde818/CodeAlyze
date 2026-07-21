import sys

N, K, S = map(int, input().split())

ans = ''
s1, s2 = 0, 0
if S % 2 == 0:
    s1 = s2 = S // 2
else:
    s1 = S // 2
    s2 = s1 + 1

ex = 10 ** 9
while ex == s1 or ex == s2 or ex == S or ex == 0:
    ex -= 1


if K == 0:
    for i in range(N): ans += str(ex) + ' '
elif K == N:
    for i in range(N): ans += str(S) + ' '
elif S == 1:
    for i in range(K): ans += str(S) + ' '
    for j in range(N-K): ans += str(ex) + ' '
else:
    for i in range(N):
        if i % 2 == 0 and i < K:
            ans += str(s1) + ' '
        elif i < K:
            ans += str(s2) + ' '
        elif i == K:
            ans += str(S) + ' '
        else:
            ans += str(ex) + ' '

print(ans.rstrip())
