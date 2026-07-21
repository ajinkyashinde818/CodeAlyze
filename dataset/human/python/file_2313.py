import itertools

D, G = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(D)]

m = 10**10
for comb in itertools.product(*[[0, 1]]*D):
    score = 0
    solve = 0
    stack = []
    for i in range(D):
        p, c = pc[i]
        if comb[i] == 1:
            solve += p
            score += p*(i + 1)*100 + c
        else:
            for j in range(p - 1):
                stack.append(i + 1)
    while score < G and len(stack) != 0:
        score += stack.pop()*100
        solve += 1
    if score >= G:
        m = min(m, solve)
print(m)
