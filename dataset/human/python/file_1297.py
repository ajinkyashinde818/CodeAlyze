from numpy import cumsum

n = int(input())
a = list(map(int, input().split()))

ans = 1000000000000000000
ruiseki = cumsum(a)
sum = ruiseki[len(ruiseki)-1]
for i in range(len(ruiseki)-1):
    x = ruiseki[i]
    y = sum - ruiseki[i]
    ans = min(ans, abs(x-y))

print(ans)
