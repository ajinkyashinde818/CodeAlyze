n, g = map(int, input().split())
inps = []
for i in range(1, n + 1):
    inp = list(map(int, input().split()))
    inp.append(inp[0] * i * 100 + inp[1])
    inp.append(i)
    inps.append(inp)
def at(items, goal):
    if goal <= 0:
        return 0
    result = 0
    for t, c, a, i in reversed(items):
        tn = i * 100
        cnt = min(t - 1, (goal + tn - 1) // tn)
        result += cnt
        goal -= cnt * tn
        if goal <= 0:
            return result
    return float("inf")
result = []
for i in range(2 ** n):
    items = []
    other = []
    for item in inps:
        (items if i & 1 else other).append(item)
        i >>= 1
    tcnt = sum(map(lambda x: x[0], items))
    acnt = sum(map(lambda x: x[2], items))
    ncnt = at(other, g - acnt)
    result.append(tcnt + ncnt)
print(min(result))
