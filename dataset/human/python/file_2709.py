from itertools import product

D, G = map(int, input().split(' '))
questions = [tuple(map(int, input().split(' '))) for _ in range(D)]
questions = [(100 * index, n, bonus) for index, (n, bonus) in enumerate(questions, start=1)]

min_answer = 1000

for bits in product((True, False), repeat=D):
    not_complete = []
    score = G
    answered = 0
    for index, bit in enumerate(bits):
        if not bit:
            not_complete.append(index)
            continue

        point, n, bonus = questions[index]
        score -= point * n + bonus
        answered += n

    if not_complete:
        index = max(not_complete)
        point, n, _ = questions[index]
        while score > 0 and n > 1:
            score -= point
            n -= 1
            answered += 1

    if score <= 0:
        min_answer = min(min_answer, answered)

print(min_answer)
