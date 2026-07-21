import sys
input = lambda: sys.stdin.readline().rstrip()
k, n = map(int, input().split())

a = list(map(int, input().split()))
sub = [abs(k - a[-1] + a[0])]

for i in range(len(a) - 1):
    tmp = abs(a[i + 1] - a[i])
    sub.append(tmp)
print(sum(sub) - max(sub))
