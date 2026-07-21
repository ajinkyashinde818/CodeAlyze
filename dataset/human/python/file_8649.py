from sys import stdin

K, N = [int(x) for x in stdin.readline().rstrip().split()]
a = [int(x) for x in input().split()]
ans1 = 100000000000000000
for i in range(N-1):
    if i == 0:
        ans1 = min(a[N-1]-a[0], K-(a[1]-a[0]))
        continue
    # print(a[i]+K-a[i+1])
    # print(K-(a[i]-a[i-1]))
    # print()
    ans = min(a[i]+K-a[i+1], K-(a[i]-a[i-1]))
    if ans1 > ans:
        ans1 = ans
print(ans1)
