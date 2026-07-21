n = int(input())
def decomp(a):
    factors = []
    sqrt = round(n ** 0.5 + 0.5)
    for i in range(2, sqrt + 1):
        if not a % i:
            count = 0
            while a % i == 0:
                count += 1
                a //= i
            factors.append((i, count))
    if a != 1:
        factors.append((a, 1))
    return factors
total = 0
for i, j in decomp(n):
    temp = 1
    while j >= temp:
        total += 1
        j -= temp
        temp += 1
print(total)
