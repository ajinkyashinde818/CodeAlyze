N = int(input())
As = list(map(int, input().split()))
from itertools import accumulate
acc = list(accumulate(As))
s = sum(As)
mn = 10**10
for i,x in enumerate(acc[:-1]):
    y = s - x
    if mn >= abs(x-y):
        mn = abs(x-y)
print(mn)
