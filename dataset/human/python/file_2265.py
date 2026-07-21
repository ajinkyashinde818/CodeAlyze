from sys import stdin

D, G = [int(x) for x in stdin.readline().rstrip().split()]

list = []
for i in range(D):
    tmp = [int(x) for x in stdin.readline().rstrip().split()]
    list.append(tmp)

ans = 1e9

for mask in range(1 << D):
    s = 0
    num = 0
    rest_max = -1
    for i in range(D):
        if mask >> i & 1:
            s += 100 * (i + 1) * list[i][0] + list[i][1]
            num += list[i][0]
        else:
            rest_max = i
    if s < G:
        s1 = 100 * (rest_max + 1)
        need = (G - s + s1 - 1) // s1
        if need >= list[rest_max][0]:
            continue
        num += need
    ans = min(ans, num)

print(ans)
