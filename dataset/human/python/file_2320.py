from math import ceil
D, G = map(int, input().split(" "))
pc = [[int(i) for i in input().split(" ")] for _ in range(D)]

s = 100 * 11
for i in range(2 ** D):
    ans = 0
    num = 0
    zero = 0
    for j in range(D):
        if (i >> j) & 1:
            ans += 100*(j+1)*pc[j][0] + pc[j][1]
            num += pc[j][0]
        else:
            zero = j
    if G > ans:
        cand = ceil((G-ans)/(100 * (zero+1)))
        if cand > pc[zero][0]:
            continue
        else:
            num += cand
    if num < s:
        s = num
print(s)
