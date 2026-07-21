import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

cnt = 0
mi = 10**9
for i in range(n):
    if a[i] < 0 or a[i] == 0:
        cnt += 1
    mi = min(mi, abs(a[i]))

sum = 0
for i in a:
    sum += abs(i)

if cnt % 2 != 0:
    print(sum - mi * 2)
else:
    print(sum)
