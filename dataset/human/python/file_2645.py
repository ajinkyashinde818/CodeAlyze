from itertools import product

D, G = map(int, input().split())
probs = []
for _ in range(D):
    p, c = map(int, input().split())
    probs.append((p, c))
ans = 10**9
for choise in product([True, False], repeat=D):
    score = 0
    solved_probs = 0
    max_score_rem_id = 0
    for i, solve in enumerate(choise):
        if solve:
            score += probs[i][0]*(100*(i+1)) + probs[i][1]
            solved_probs += probs[i][0]
        else:
            max_score_rem_id = i
    if score < G:
        remain = G - score
        to_be_solved = (remain - 100) // (100*(max_score_rem_id+1)) + 1
        if to_be_solved < probs[max_score_rem_id][0]:
            solved_probs += to_be_solved
        else:
            continue
    ans = min(ans, solved_probs)
print(ans)
