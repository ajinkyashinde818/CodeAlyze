import collections
n = int(input())

a = list(input())

l = collections.Counter()
co = 1

for i in a:
    l[i] += 1
l = list(l.most_common())
for i in range(len(l)):
    co *= l[i][1]+1

print((co-1)%(10**9+7))
