import sys
input = lambda: sys.stdin.readline().rstrip()
n = int(input())
a = list(map(int, input().split()))
summ = sum(a)
ruisekiwa = []
tmp = 0
for i in range(n):
    tmp += a[i]
    ruisekiwa.append(tmp)
ans = 100100100100
for i in range(len(ruisekiwa) - 1):
    ans = min(ans, abs(ruisekiwa[i] - (summ - ruisekiwa[i])))
print(ans)
# print(ruisekiwa)
