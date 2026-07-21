import itertools

n = int(input())
lis = list(map(int, input().split()))
k = list(itertools.accumulate(lis))
x = sum(lis)

ans = 100100100100100100

for i in range(n-1):
    t = k[i]
    t2 = x - t
    
    ans = min(ans, abs(t-t2))

print(ans)
