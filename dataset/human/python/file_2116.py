from collections import Counter

n = int(input())
s = input()
counter = Counter(s)
ans = 1

for char, count in counter.items():
    if count != 1:
        ans = ans * (count + 1) % (10 ** 9 + 7)
    else:
        ans = ans * 2 % (10 ** 9 + 7)
print(ans - 1)
