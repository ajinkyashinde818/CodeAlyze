import itertools

n = int(input())
ls = list(map(int, input().split()))
accs = [0] + list(itertools.accumulate(ls))
res = float('inf')
for i in range(1, n):
    res = min(res, abs(accs[i] * 2 - accs[n]))
print(res)
