import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")

n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()][::-1]

ng = []
for i in range(n):
    if a[i] == b[i]:
        ng.append(i)

if len(ng) == 0:
    print('Yes')
    print(*b)
    sys.exit()

min_ng = min(ng)
max_ng = max(ng)

left = 0
right = n - 1

for i in ng:
    if b[i] != b[left] and a[left] != b[i]:
        b[i], b[left] = b[left], b[i]
        left += 1
        continue
    if b[i] != b[right] and a[right] != b[i]:
        b[i], b[right] = b[right], b[i]
        right -= 1

flag = 1

for i in range(n):
    if a[i] == b[i]:
        flag = 0

if flag:
    print('Yes')
    print(*b)
else:
    print('No')
