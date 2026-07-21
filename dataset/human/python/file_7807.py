import itertools

n, k, s = map(int, input().split())
ans = [0] * n

if s == 1000000000:
    for i in range(n):
        if i < k:
            ans[i] = s
        else:
            ans[i] = 1
else:
    for i in range(n):
        if i < k:
            ans[i] = s
        else:
            ans[i] = s+1

for i in ans:
    print(i, end=" ")
print()
