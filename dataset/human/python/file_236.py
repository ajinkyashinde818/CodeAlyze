import sys

N = int(input())

for i in range(1, N + 1):
    if i * (i + 1) // 2 == N:
        K = i
        break
else:
    print('No')
    sys.exit(0)

anss = [[] for _ in range(K + 1)]
x = 1
iAns = 0
for i in reversed(range(1, K + 1)):
    anss[iAns].append(x)
    anss[-1].append(x)
    for j in range(1, i):
        anss[iAns].append(x + j)
        anss[iAns + j].append(x + j)
    x += i
    iAns += 1

print('Yes')
print(K + 1)
for ans in anss:
    print(len(ans), ' '.join(map(str, ans)))
