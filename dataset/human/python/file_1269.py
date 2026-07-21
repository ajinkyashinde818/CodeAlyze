import itertools
N = int(input())
a = list(map(int,input().split()))
ruiseki = list(itertools.accumulate(a))
b = sum(a)
ans = 10**100
for i in range(N-1):
    ans = min(ans,abs(ruiseki[i]*2-b))
print(ans)
