from itertools import product


def f(comb, ans, scores):
    score = 0
    problems = 0
    for i, bi in enumerate(comb):
        if bi == 1:
            score += scores[i][1] + scores[i][0] * 100 * (i + 1)
            problems += scores[i][0]

    if score >= g:
        return min(ans, problems)

    else:
        for j in reversed(range(d)):
            if comb[j] == 0:
                for _ in range(1, scores[j][0]):
                    problems += 1
                    score += (j + 1) * 100
                    if score >= g:
                        ans = min(ans, problems)
                        return ans

        return ans


d, g = map(int, input().split())

scores = []
for _ in range(d):
    pc = list(map(int, input().split()))
    scores.append(pc)

ans = float("inf")
for comb in product((0, 1), repeat=d):
    ans = f(comb, ans, scores)

print(ans)
