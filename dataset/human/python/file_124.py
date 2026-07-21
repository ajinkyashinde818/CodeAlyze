import math
line = [int(x) for x in input().split(" ")]
r = line[0]
g = line[1]
b = line[2]
n = line[3]
m = [r,g,b]
m.sort()
m.reverse()

res = 0

ro1 = list(range(math.floor(n / m[0]) + 1))
ro1.reverse()

for i in ro1:
    p = i * m[0]
    ro2 = list(range(math.floor((n - p) / m[1]) + 1))
    ro2.reverse()
    for j in ro2:
        q = p + j * m[1]

        if (n - q) % m[2] == 0:
            res += 1
print(res)
