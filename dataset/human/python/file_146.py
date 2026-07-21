from collections import defaultdict
r, g, b, n = map(int, input().split())

dic = defaultdict(int)
for i in range(n // r + 1):
    for j in range(n // g + 1):
        dic[i * r + j * g] += 1


ans = 0
for k in range(n // b + 1):
    num = n - k * b
    ans += dic.get(num, 0)
print(ans)
