from math import ceil

d, g = map(int, input().strip().split())
points = [list(map(int, input().strip().split())) for _ in range(d)]

answer = float("inf")
for combination in range(2 ** d):
    score = 0
    solved = 0
    for difficuty in range(d):
        if (combination >> difficuty) & 1:
            score += points[difficuty][0] * 100 * (difficuty + 1) + points[difficuty][1]
            solved += points[difficuty][0]
    if score < g:
        for difficuty in range(d)[::-1]:
            if not (combination >> difficuty) & 1 and g - score < points[difficuty][0] * 100 * (difficuty + 1):
                solved += ceil((g - score) / (100 * (difficuty + 1)))
                break
        else:
            continue
    if answer > solved:
        answer = solved
print(answer)
