import collections
n = int(input())
s = input()
c = collections.Counter(list(s))
a = list(c.values())
count = 0
r = 1
for i in range(len(a)):
    if a[i] == 1:
        count += 1
    else:
        r *= (a[i] + 1)

print((2 ** count * r - 1) % (10 ** 9 + 7))
