import heapq

D, G = map(int, input().split())

problems = []
for i in range(D):
    p, c = map(int, input().split())
    total_score = 100 * (i + 1) * p + c
    problems.append([100 * (i + 1), p, c, total_score])

counts = []
for i in range(2**D):
    Bin = str(bin(i))[2:].zfill(D)
    score = 0
    count = 0
    index = -1
    for j, c in enumerate(Bin):
        if int(c):
            score += problems[j][3]
            count += problems[j][1]
        else:
            index = j
    if score >= G:
        heapq.heappush(counts, count)
    elif index != -1:
        div, mod = divmod((G - score), problems[index][0])
        if mod != 0:
            div += 1
        if div < problems[index][1]:
            count += div
            heapq.heappush(counts, count)

print(heapq.heappop(counts))
