import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)

D, G = map(int, readline().split())
problems = []
for i in range(1, D+1):
    p, c = map(int, readline().split())
    score = 100 * i
    problems.append({
        "score": score,
        "number": p,
        "bonus": c,
        "sum": score * p + c
    })

keta = len(problems)
answer = float("inf")
for i in range(0, 2 ** D):
    bits = list(str(format(i, "0{}b".format(keta))))
    sum_number = 0
    sum_score = 0
    half_index = None
    for j, is_full in enumerate(bits):
        if is_full == "1":
            sum_number += problems[j]["number"]
            sum_score += problems[j]["sum"]
        else:
            half_index = j
    if half_index is None:
        if sum_score >= G:
            answer = min(answer, sum_number)
        continue
    for _ in range(problems[half_index]["number"]):
        if sum_score >= G:
            break
        sum_score += problems[half_index]["score"]
        sum_number += 1
    if sum_score >= G:
        answer = min(answer, sum_number)

print(answer)
