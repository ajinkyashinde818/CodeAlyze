import itertools
N = int(input())
X = int(((8 * N + 1)**0.5 - 1) // 2)
if N != X * (X + 1) // 2:
    print('No')
    exit()
index = 0
ans = [[X] for _ in range(X + 2)]
for i, j in itertools.combinations(range(1, X + 2), 2):
    index += 1
    ans[i] += [index]
    ans[j] += [index]
print('Yes')
print(X + 1)
[print(*_) for _ in ans[1:]]
