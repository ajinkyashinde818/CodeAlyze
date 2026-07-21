import math
d, g = map(int, input().split())
lst = [list(map(int, input().split())) for _ in range(d)]
for i in range(d):
    lst[i].append((i+1) * 100)
    lst[i].append((i+1) * 100 * lst[i][0] + lst[i][1])

def make_bit(n, d):
    bit = [0] * d
    for i in range(d):
        bit[i] += n % 2
        n //= 2
    return bit

min_count = 10 ** 9 + 7
for n in range(2 ** d):
    bit = make_bit(n, d)
    #print(bit)
    now = 0
    count = 0
    for i in range(d):
        if bit[i] == 1:
            now += lst[i][3]
            count += lst[i][0]
    if now >= g:
        min_count = min(min_count, count)
    else:
        for i in range(d-1, -1, -1):
            if bit[i] == 0:
                c = math.ceil((g - now) / lst[i][2])
                if c < lst[i][0]:
                    count += c
                    min_count = min(min_count, count)
                break
print(min_count)
