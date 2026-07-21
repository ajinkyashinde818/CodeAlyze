from sys import stdin

k, s = map(int, stdin.readline().split())

result = 0


def get_variants(target, maximum):
    result = 0
    for x in range(maximum, -1, -1):
        y = target - x
        if 0 <= y <= maximum:
            result += 1
    return result

for z in range(k+1):
    variants = get_variants(s - z, k)
    result += variants

print(result)
