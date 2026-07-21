from itertools import product


D, G = map(int, input().split())
pc = [tuple(map(int, input().split())) for _ in range(D)]


ans = 1e9
for selected in product((True, False), repeat=D):
    tmp_score = 0
    tmp_count = 0
    rest_max = 0

    for i, is_select in enumerate(selected):
        if is_select:
            tmp_score += 100 * (i + 1) * pc[i][0] + pc[i][1]
            tmp_count += pc[i][0]
        else:
            rest_max = i

    if tmp_score < G:
        s1 = 100 * (rest_max + 1)
        need = (G - tmp_score + s1 - 1) // s1

        if need >= pc[rest_max][0]:
            continue

        tmp_count += need

    ans = min(ans, tmp_count)

print(ans)
