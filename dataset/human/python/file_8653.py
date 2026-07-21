import copy
k, n = map(int, input().split())
a = list(map(int, input().split()))
tonari = copy.copy(a)
last = tonari.pop(0)
tonari.append(last + k)
for i in range(n):
    a[i] = tonari[i]-a[i]
print(k - max(a))
