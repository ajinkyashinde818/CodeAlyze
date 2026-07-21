n = int(input())
a = list(map(int, input().split()))

ans = 0
abs_mina = 10 ** 10
import copy
copy_a = copy.copy(a)
sum_a = 0

for i in range(n - 1):
    if copy_a[i] < 0:
        copy_a[i] *= -1
        copy_a[i + 1] *= -1

for i in a:
    ans += abs(i)
    abs_mina = min(abs_mina, abs(i))

if copy_a[-1] < 0:
    ans -= abs_mina * 2


print(ans)
