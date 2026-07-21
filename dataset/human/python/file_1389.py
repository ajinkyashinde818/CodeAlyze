import itertools
n = input()
m = list(map(int, input().split()))
s = sum(m)
f = lambda x: abs(x-(s-x))
ans = f(m[0])
for i in list(itertools.accumulate(m))[1:-2]:
    ans = min(ans, f(i))
print(ans)
