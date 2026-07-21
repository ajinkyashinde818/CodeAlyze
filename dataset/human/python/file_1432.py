import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
sum_a = sum(a)
sunuke = 0
ans = [0]*(n-1)
for i in range(n-1):
    sunuke += a[i]
    ans[i] = abs(sum_a-(2*sunuke))
print(min(ans))
