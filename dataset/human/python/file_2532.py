import itertools


def is_achievable(problems_fully_solved, target):
    score = 0
    n_problems_solved = 0
    for problem in problems_fully_solved:
        score += p_n[problem] * 100 * problem + c_n[problem]
        n_problems_solved += p_n[problem]
    if score >= target:
        return True, n_problems_solved
    problem_partially_solved = max(set(range(1, D+1)) - set(problems_fully_solved))
    for _ in range(1, p_n[problem_partially_solved]):
        score += problem_partially_solved * 100
        n_problems_solved += 1
        if score >= target:
            return True, n_problems_solved
    return False, None


D, G = map(int, input().split(" "))
p_n, c_n = [None, ], [None, ]

for i in range(1, D+1):
    p, c = map(int, input().split(" "))
    p_n.append(p)
    c_n.append(c)

answer = 10000
for combination in itertools.product([True, False], repeat=D):
    l = [i+1 for i in range(D) if combination[i]]
    flag, n_problems_solved = is_achievable(l, G)
    if flag:
        if n_problems_solved < answer:
            answer = n_problems_solved
print(answer)
