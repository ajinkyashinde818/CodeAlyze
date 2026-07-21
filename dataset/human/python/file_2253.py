import itertools
import math
D, G = list(map(int, input().split(' ')))
p_list = list()
c_list = list()
for _ in range(D):
    p, c = list(map(int, input().split(' ')))
    p_list.append(p)
    c_list.append(c)
ans = sum(p_list)
pattern_list = itertools.product([0, 1], repeat=D)
for pattern in pattern_list:
    score = 0
    prob_num = 0
    # Solve all problems with bit `1`
    score += sum([bit * (100 * (index + 1) * p_list[index] + c_list[index]) for index, bit in enumerate(pattern)])
    prob_num += sum([bit * p_list[index] for index, bit in enumerate(pattern)])
    # Solve problems partially with bit `0'
    if score < G:
        for index in range(D - 1, -1, -1):
            if pattern[index] == 1:
                # skip because these cases are already counted
                continue
            required_num = math.ceil((G - score) / (100 * (index + 1)))
            sol_num = min([p_list[index] - 1, required_num])
            score += 100 * (index + 1) * sol_num
            prob_num += sol_num
            if score >= G:
                break
    # update answer
    if score >= G:
        ans = min([ans, prob_num])
print(ans)
