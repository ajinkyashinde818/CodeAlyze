def f(x):
    return int(x)-1
n, k = map(int, input().split())
a = list(map(f, input().split()))
town = 0
i=0
l = [-1] * n
while True:
    if l[town] != -1:
        j = l[town]
        break
    i += 1
    l[town] += i
    town = a[town]
    # print(town,l)
# print(town)
if k >= i:
    k = (k - j) % (i - j) + j
print(l.index(k)+1)
