fn = lambda: map(int, input().split())
D, G = fn()
p, c = [0] * D, [0] * D
complete_scores = [0] * D
for i in range(D):
    p[i], c[i] = fn()
    complete_scores[i] = 100 * (i + 1) * p[i] + c[i]

def calc(x):
    value = 0
    count = 0
    i_unused = None
    for i, xi in enumerate(x):
        if xi == '1':
            value += complete_scores[i]
            count += p[i]
        else:
            i_unused = i
    if i_unused is not None:
        for _ in range(p[i_unused]):
            if value >= G:
                break
            else:
                value += (i_unused + 1) * 100
                count += 1
    if value < G:
        return float('inf')
    else:
        return count

fmt = '0{}b'.format(D)
x = format(0, fmt)
best_count = float('inf')
while len(x) <= D:
    best_count = min(calc(x), best_count)
    x = format(int(x, 2) + 1, fmt)

print(best_count)
